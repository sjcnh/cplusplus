 ///
 /// @file    msgget.c
 /// @author  LJW
 /// @date    2018-07-27 16:49:28
 ///
 
#include "func.h"
typedef struct mgbuf
{
	long mtype;
	char buf[128];
} Msg;

int main()
{
	int msqid;
	msqid = msgget(1000, IPC_CREAT | 0600);
	printf("msqid = %d\n", msqid);
	Msg mBuf;
	mBuf.mtype = 1;
	strcpy(mBuf.buf, "hello");
	int ret = msgsnd(msqid, &mBuf, sizeof(mBuf.buf), 0);
	if(-1 == ret)
	{
		perror("msgsnd");
		return -1;
	}
	return 0;
}
