 ///
 /// @file    orphan.c
 /// @author  LJW
 /// @date    2018-07-25 10:53:06
 ///
 
#include "func.h"

int main()
{
	pid_t pid = fork();
	if(pid > 0)
	{
		printf("I am parent,mypid = %d, ppid = %d\n", getpid(), getppid());
	}
	else
	{
		printf("I am child,mypid = %d, ppid = %d\n", getpid(), getppid());
		while(1);
	}

}
