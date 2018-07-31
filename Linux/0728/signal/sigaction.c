 ///
 /// @file    sigaction.c
 /// @author  LJW
 /// @date    2018-07-28 22:40:03
 ///
 
#include "func.h"
void myfunc(int no)
{
	sleep(3);
	printf("catch %d signal!\n", no);
}

int main()
{
	struct sigaction act;
	act.sa_flags = 0;
	sigemptyset(&act.sa_mask);
	// 添加临时屏蔽信号
	sigaddset(&act.sa_mask, SIGQUIT);
	act.sa_handler = myfunc;
	sigaction(SIGINT, &act, NULL);
	while(1);
	return 0;
}
