 ///
 /// @file    add1000.c
 /// @author  LJW
 /// @date    2018-07-26 17:15:25
 ///
 
#include "../func.h"
#define N 10000000

int main()
{
	int shmid;
	int semid;
	shmid = shmget(1000, 4096, IPC_CREAT | 0600);
	semid = semget(1000, 1, IPC_CREAT | 0600);
	int *p;
	p = (int *)shmat(shmid, NULL, 0);
	p[0] = 0;
	struct sembuf sopp, sopv;  // p加锁， v解锁
	sopp.sem_num = 0;
	sopp.sem_op = -1;
	sopp.sem_flg = SEM_UNDO;
	sopv.sem_num = 0;
	sopv.sem_op = 1;
	sopv.sem_flg = SEM_UNDO;
	// 创建信号量后需要设置 semctl的SETVAL 1
	int ret = semctl(semid, 0, SETVAL, 1); 
	if(-1 == ret)
	{
		perror("semctl");
		return - 1;
	}
	if(!fork())
	{
		int i;
		for(i = 0; i < N; ++i)
		{
			semop(semid, &sopp, 1); // 1是sembuf个数
			p[0] += 1;
			semop(semid, &sopv, 1);
		}
	}
	else
	{
		int i;
		for(i = 0; i < N; ++i)
		{
			semop(semid, &sopp, 1);
			p[0] += 1;
			semop(semid, &sopv, 1);
		}
		wait(NULL); // 回收子进程
		printf("p[0] = %d\n", p[0]);
		//shmctl(shmid, IPC_RMID, NULL);
		//semctl(semid, IPC_RMID, 0);
	}
}	
