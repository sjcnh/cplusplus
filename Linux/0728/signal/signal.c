 ///
 /// @file    signal.c
 /// @author  LJW
 /// @date    2018-07-28 22:08:15
 ///
 
#include "func.h"

void myfunc(int no)
{
	printf("catch you signal: %d\n", no);
}

int main()
{
	// set struct
	struct itimerval new_val;
	// 第一次触发时间
	new_val.it_value.tv_sec = 1;
	new_val.it_value.tv_usec = 0;
	// 周期执行时间
	new_val.it_interval.tv_sec = 2;
	new_val.it_interval.tv_usec = 0;

	// 定时规则，新的结构体，旧结构体（传出函数）
	setitimer(ITIMER_REAL, &new_val, NULL);  // ITIMER_REAL --->  SIGALRM

	// 捕捉信号
	signal(SIGALRM, myfunc);
	while(1)
	{
		printf("hello\n");
		sleep(1);
	}

	return 0;
}
