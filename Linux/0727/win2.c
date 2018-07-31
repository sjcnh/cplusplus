///
/// @file    semgetMore.c
/// @author  LJW
/// @date    2018-07-26 21:09:38
///

#include "func.h"

int main()
{
	int semid = semget(1000, 1, IPC_CREAT | 0600);
	semctl(semid, 0, SETVAL, 1);
	struct sembuf sopp, sopv;
	sopp.sem_num = 0;
	sopp.sem_op = -1;
	sopp.sem_flg = SEM_UNDO;
	sopv.sem_num = 0; // 两个信号量
	sopv.sem_op = 1;
	sopv.sem_flg = SEM_UNDO;
	while(1)
	{
		semop(semid, &sopv, 1);
		sleep(1);
		printf("semval = %d\n", semctl(semid, 0, GETVAL, 1));
	}
	return 0;
}

