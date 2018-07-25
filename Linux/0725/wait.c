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
		pid_t wpid;
		int status;
		wpid = wait(&status);
		if(WIFEXITED(status))
		{
			printf("wpid = %d\n", wpid);
			printf("child exit code = %d\n", WEXITSTATUS(status));
		}
		else
		{
			printf("child process is abnormal\n");
		}
		if(WIFSIGNALED(status))
		{
			printf("wpid = %d\n", wpid);
			printf("child exit by signal = %d\n", WTERMSIG(status));
		}
	}
	else
	{
		printf("I am child,mypid = %d, ppid = %d\n", getpid(), getppid());
		while(1);
		return 11;
	}
}
