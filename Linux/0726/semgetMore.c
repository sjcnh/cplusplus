 ///
 /// @file    semgetMore.c
 /// @author  LJW
 /// @date    2018-07-26 21:09:38
 ///
 
#include "func.h"

int main()
{
	int semid = semget(1000, 2, IPC_CREAT | 0600);
	unsigned short arr[2] = {3, 5};
	unsigned short arr1[2] = {0};
	int ret;
	ret = semctl(semid, 0, SETALL, arr);
	memcpy(arr, arr1, sizeof(arr));
	printf("arr[0] = %d, arr[1] = %d\n", arr[0], arr[1]);
	ret = semctl(semid, 0, GETALL, arr);
	printf("arr[0] = %d, arr[1] = %d\n", arr[0], arr[1]);

	return 0;
}
