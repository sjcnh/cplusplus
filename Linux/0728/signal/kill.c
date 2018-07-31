 ///
 /// @file    kill.c
 /// @author  LJW
 /// @date    2018-07-28 16:46:39
 ///
 
#include "func.h"

int main()
{
	if(!fork())
	{
		sleep(3);
		kill(getppid(), SIGKILL);

		return 0;
	}
	else
	{
		printf("good bye");
		wait(NULL);
		return 0;
	}

}
