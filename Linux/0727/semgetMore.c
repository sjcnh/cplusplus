///
/// @file    semgetMore.c
/// @author  LJW
/// @date    2018-07-26 21:09:38
///

#include "func.h"

int main()
{
	int semid = semget(1000, 2, IPC_CREAT | 0600);
	unsigned short arr[2] = {20, 0}; // 设置两个信号量的初始值,即仓库空位和商品个数
	int ret;
	ret = semctl(semid, 0, SETALL, arr); // 设置好
	struct sembuf sopp, sopv;
	if(!fork())
	{
		sopp.sem_num = 0;
		sopp.sem_op = -1;
		sopp.sem_flg = SEM_UNDO;
		sopv.sem_num = 1; // 两个信号量
		sopv.sem_op = 1;
		sopv.sem_flg = SEM_UNDO;
		while(1)
		{
			printf("before pro:\n");
			printf("space num = %d\n", semctl(semid, 0, GETVAL));
			printf("goods num = %d\n", semctl(semid, 1, GETVAL));
			semop(semid, &sopp, 1);
			semop(semid, &sopv, 1);
			printf("after pro:\n");
			printf("space num = %d\n", semctl(semid, 0, GETVAL));
			printf("goods num = %d\n", semctl(semid, 1, GETVAL));
			sleep(1);
		}

	}
	else
	{
		sopp.sem_num = 1;
		sopp.sem_op = -1;
		sopp.sem_flg = SEM_UNDO;
		sopv.sem_num = 0; // 两个信号量
		sopv.sem_op = 1;
		sopv.sem_flg = SEM_UNDO;
		while(1)
		{
			printf("before cus:\n");
			printf("space num = %d\n", semctl(semid, 0, GETVAL));
			printf("goods num = %d\n", semctl(semid, 1, GETVAL));
			semop(semid, &sopp, 1);
			semop(semid, &sopv, 1);
			printf("after cus:\n");
			printf("space num = %d\n", semctl(semid, 0, GETVAL));
			printf("goods num = %d\n", semctl(semid, 1, GETVAL));
			sleep(2);
		}
	}

	return 0;
}
