 ///
 /// @file    shmget.c
 /// @author  LJW
 /// @date    2018-07-25 23:26:54
 ///
 
#include "func.h"

int main(int argc, char *argv[])
{
	if(2 != argc)
	{
		printf("error args!\n");
		return -1;
	}
	int shmid;
	shmid = shmget(1000, 4096, IPC_CREAT | 0600);
	printf("shmid = %d\n", shmid);
	int *p;
	p = (int *)shmat(shmid, NULL, 0);
	if((int *)-1 == p)
	{
		perror("shmat");
		return -1;
	}
	//p[0] = 1000;
	printf("p[0] = %d\n", p[0]);
	

	return 0;
}
