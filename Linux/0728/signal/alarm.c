 ///
 /// @file    alarm.c
 /// @author  LJW
 /// @date    2018-07-28 17:25:29
 ///
 
#include "func.h"

int main()
{
	int ret = alarm(5);
	printf("ret = %d\n", ret);
	sleep(2);
	ret = alarm(2);
	printf("ret = %d\n", ret);
	while(1)
	{
		printf("hello!\n");
		sleep(1);
	}

	return 0;
}
