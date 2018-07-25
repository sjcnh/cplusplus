 ///
 /// @file    daemon.c
 /// @author  LJW
 /// @date    2018-07-25 15:39:12
 ///

#include "func.h"

int main()
{
	pid_t pid = fork();
	if(pid > 0)
	{
		int status;
		printf("pid = %d, ppid = %d, pgid = %d, sid = %d\n", getpid(), getppid(), getpgid(0), getsid(0));
		waitpid(pid, &status, WNOHANG);
	}
	else
	{
		printf("pid = %d, ppid = %d, pgid = %d, sid = %d\n", getpid(), getppid(), getpgid(0), getsid(0));
		setsid();
		printf("pid = %d, ppid = %d, pgid = %d, sid = %d\n", getpid(), getppid(), getpgid(0), getsid(0));

		return 0;
	}

}
