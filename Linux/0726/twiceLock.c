///
/// @file    twiceLock.c
/// @author  LJW
/// @date    2018-07-26 20:54:48
///

#include "func.h"

int main()
{
	int semid = semget(1000, 1, IPC_CREAT | 0600); 
	int ret = semctl(semid, 0, SETVAL, 1);
	if(-1 == ret)
	{
		perror("semctl");
		return 0;
	}
	struct sembuf sopp, sopv;
	sopp.sem_num = 0;
	sopp.sem_op = -1;
	sopp.sem_flg = SEM_UNDO;
	sopv.sem_num = 0;
	sopv.sem_op = 1;
	sopv.sem_flg = SEM_UNDO;
	if(!fork())
	{
		semop(semid, &sopp, 1);
		printf("child lock once, success!\n");
		semop(semid, &sopp, 1);
		printf("child wake up!\n");
	}
	else
	{
		semop(semid, &sopp, 1);
		printf("parent lock once, success!\n");
		semop(semid, &sopp, 1);
		printf("child wake up!\n");

	}
	return 0;
}
