 ///
 /// @file    semget.c
 /// @author  LJW
 /// @date    2018-07-26 16:46:41
 ///
 
#include "../func.h" 


int main()
{
	int semid;
	semid = semget(1000, 1, IPC_CREAT | 0600);
#ifdef DEBUG
	if(-1 == semid)
	{
		perror("semget");
		return -1;
	}
#endif
	return 0;

}
