///
/// @file    sellTicket.c
/// @author  LJW
/// @date    2018-07-26 19:35:05
///

#include "func.h"
#define N 200

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
	semctl(semid, 0, SETVAL, 1);
	int cnt;
	//if(-1 == ret)
	//{
	//	perror("semctl");
	//	return -1;
	//}	
	if(!fork())
	{
		cnt = 0;
		while(1)
		{
			semop(semid, &sopp, 1);
			if(p[0] > 0)
			{
				printf("child sold will ticket, now totol tickest left %d\n", p[0]);
				p[0]--;
				++cnt;
				printf("child sold one ticket, after that totol tickest is %d\n", p[0]);
				semop(semid, &sopv, 1);
			}
			else
			{
				semop(semid, &sopv, 1);
				break;
			}
		}
		printf("child totol sold tickest is %d\n", cnt);
		return 0;
	}
	else
	{
		cnt = 0;
		while(1)
		{
			semop(semid, &sopp, 1);
			if(p[0] > 0)
			{
				printf("parent sold will ticket, now totol tickest left %d\n", p[0]);
				p[0]--;
				++cnt; // 写时复制，所以和子进程的cnt并不互相影响
				printf("parent sold one ticket, after that totol tickest is %d\n", p[0]);
				semop(semid, &sopv, 1);
			}
			else
			{
				semop(semid, &sopv, 1);
				break;
			}
		}
		wait(NULL);
		printf("parent totol sold tickest is %d\n", cnt);
		// 回收共享内存和信号
		shmctl(shmid, IPC_RMID, NULL);
		semctl(semid, IPC_RMID, 0);

		return 0;
	}
}
