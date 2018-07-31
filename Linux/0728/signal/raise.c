 ///
 /// @file    raise.c
 /// @author  LJW
 /// @date    2018-07-28 16:59:17
 ///
 
#include "func.h"

int main()
{
	pid_t pid = fork();
	if(pid > 0)
	{
		int status;
		pid_t wpid = wait(&status);
		printf("child died pid = %d\n", wpid);
		if(WIFSIGNALED(status))
		{
			printf("died by signal: %d\n", WTERMSIG(status));
		}
	}
	else
	{
		abort();
		raise(SIGQUIT);
	}
	return 0;
}
