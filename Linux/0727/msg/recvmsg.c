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
	memset(&mBuf, 0, sizeof(mBuf));
	mBuf.mtype = 1;
	int ret = msgrcv(msqid, &mBuf, sizeof(mBuf.buf), 0, 0); // 接收第一个消息
	if(-1 == ret)
	{
		perror("msgsnd");
		return -1;
	}
	printf("recv : %s\n", mBuf.buf);
	return 0;
}
