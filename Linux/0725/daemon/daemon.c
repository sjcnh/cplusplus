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
		setsid();
		chdir("/");
		umask(0);
		int i;
		for(i = 0; i < 2; ++i)
		{
			close(i);
		}
		while(1)
		{
			sleep(1);
		}

		return 0;
	}

}
