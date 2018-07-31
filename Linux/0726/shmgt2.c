 ///
 /// @file    shmgt.c
 /// @author  LJW
 /// @date    2018-07-26 10:49:42
 ///
 
#include "func.h"
#define N 10000000

int main()
{
	int shmid;
	shmid = shmget(IPC_PRIVATE, 4096, IPC_CREAT | 0600);
	printf("shmid =  %d\n", shmid);
	int *p;
	p = (int *)shmat(shmid, NULL, 0);
	p[0] = 0;
	if(!fork())
	{
		printf("i am chlid\n");
		int i;
		for(i = 0; i < N; ++i)
		{
			p[0] += 1;
		}
		return 0;
	}
	else
	{
		printf("i am parent\n");
		int i;
		for(i = 0; i < N; ++i)
		{
			p[0] += 1;
		}

		wait(NULL);
		printf("p[0] = %d\n", p[0]);
		int ret = shmdt(p);
		printf("ret = %d\n", ret);
		ret = shmctl(shmid, IPC_RMID, NULL); 
	}
}
