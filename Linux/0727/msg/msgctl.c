 ///
 /// @file    msgctl.c
 /// @author  LJW
 /// @date    2018-07-27 20:09:12
 ///
 
#include "func.h"

int main()
{
	int msqid;
	msqid = msgget(1000, IPC_CREAT | 0600);
	int ret = msgctl(msqid, IPC_RMID, NULL);
	return 0;

}
