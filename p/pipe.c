 ///
 /// @file    pipe.c
 /// @author  LJW
 /// @date    2018-07-09 22:19:39
 ///
 
#include "func.h"

int main()
{
	int fd[2];
	int ret = pipe(fd);
	if(-1 == ret)
	{
		perror("pipe error");
		return -1;
	}
	pid_t pid = fork();
	if(pid > 0)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		execlp("ps", "ps", "aux", NULL);
		perror("execlp");
		exit(1);
	}
	else if(pid == 0)
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		execlp("grep", "grep", "--color=auto", "bash", NULL);
		// execlp错误才会执行下面语句
		perror("execlp");
		exit(1);
	}

	printf("pipe[0] = %d " , fd[0]);
	printf("pipe[1] = %d " , fd[1]);

	close(fd[0]);
	close(fd[1]);
	return 0;
}
