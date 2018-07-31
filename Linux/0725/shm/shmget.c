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
	key_t key;
	int shmid;
	key = ftok(argv[1], 1);
	printf("key = %d\n", key);
	shmid = shmget(key, 4096, IPC_CREAT | 0600);
	printf("shmid = %d\n", shmid);
	return 0;

}
