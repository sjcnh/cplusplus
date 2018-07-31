 ///
 /// @file    count.c
 /// @author  LJW
 /// @date    2018-07-28 17:28:22
 ///
 
#include "func.h"

int main()
{
	int cnt = 0;
	alarm(1);
	while(1)
	{
		printf("%d\n", ++cnt);
	}
}
