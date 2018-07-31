 ///
 /// @file    msgctl_stat.c
 /// @author  LJW
 /// @date    2018-07-27 20:24:48
 ///
 
#include "func.h"

int main()
{
	int msqid;
	msqid = msgget(1000, IPC_CREAT | 0600);
	struct msqid_ds buf;
	int ret = msgctl(msqid, IPC_STAT, &buf);
	if(-1 == ret)
	{
		perror("msgctl");
		return -1;
	}
	printf("cuid = %d, mode = %o, msg_qnum = %ld\n", buf.msg_perm.cuid, buf.msg_perm.mode, buf.msg_qnum); 
	return 0;
}
