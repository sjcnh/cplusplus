 ///
 /// @file    msgget.c
 /// @author  LJW
 /// @date    2018-07-27 16:49:28
 ///
 
#include "func.h"

int main()
{
	int msgid;
	msgid = msgget(1000, IPC_CREAT | 0600);
	printf("msgid = %d\n", msgid);
	return 0;

}
