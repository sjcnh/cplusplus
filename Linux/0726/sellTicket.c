 ///
 /// @file    sellTicket.c
 /// @author  LJW
 /// @date    2018-07-26 19:35:05
 ///
 
#include "func.h"
#define N 20000000

int main()
{
	int shmid;
	int semid;
	shmid = shmget(1000, 4096, IPC_CREAT | 0600);
	semid = semget(1000, 1, IPC_CREAT | 0600);
	int *p;
	p = (int *)shmat(shmid, NULL, 0);
	p[0] = N;
	struct sembuf sopp, sopv;
	sopp.sem_num = 0;
	sopp.sem_op = -1;
	sopp.sem_flg = SEM_UNDO;
	sopv.sem_num = 0;
	sopv.sem_op = 1;
	sopv.sem_flg = SEM_UNDO;
	int ret = semctl(semid, 0, SETVAL, 1);
	if(-1 == ret)
	{
		perror("semctl");
		return -1;
	}	
	if(!fork())
	{
		// child
		int i = N / 2; 
		int cntChild = 0;
		for(;i > 0; --i)
		{
			semop(semid, &sopp, 1);
			p[0] -= 1;
			++cntChild;
			//printf("child sold one ticket, now totol tickest left %d\n", p[0]);
			semop(semid, &sopv, 1);
		}
		printf("child sold one ticket, now totol tickest is %d\n", cntChild);
		return 0;
	}
	else
	{
		int i = N / 2; 
		int cntParent = 0;
		for(;i > 0; --i)
		{
			semop(semid, &sopp, 1);
			p[0] -= 1;
			++cntParent;
			//printf("parent sold one ticket, now totol tickest left %d\n", p[0]);
			semop(semid, &sopv, 1);
		}
		wait(NULL);
		printf("child sold one ticket, now totol tickest is %d\n", cntParent);
		// 回收共享内存和信号
		shmctl(shmid, IPC_RMID, NULL);
		semctl(semid, IPC_RMID, 0);
		
		return 0;
	}
}
