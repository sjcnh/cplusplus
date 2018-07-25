///
/// @file    chata.c
/// @author  LJW
/// @date    2018-07-23 17:19:15
///

#include "func.h"
int main(int argc, char *argv[])
{
	if(3 != argc)
	{
		printf("error args!\n");
		return -1;
	}
	int fdr, fdw;
	fdr = open(argv[1], O_RDONLY);
	fdw = open(argv[2], O_WRONLY);
	char buf[128] = {0};
	int ret;
	fd_set rdset;
	struct timeval t;
	bzero(&t, sizeof(t));
	while(1)
	{
		FD_ZERO(&rdset); // clear
		FD_SET(0, &rdset);
		FD_SET(fdr, &rdset);
		t.tv_sec = 2;
		ret = select(fdr + 1, &rdset, NULL, NULL, &t);
		if(ret > 0)
		{
			if(FD_ISSET(fdr, &rdset))
			{
				memset(buf, 0, sizeof(buf));
				ret = read(fdr, buf, sizeof(buf));
				if(0 == ret)
				{
					printf("bye~\n");
					break;
				}
				printf("%s\n", buf);
			}
			if(FD_ISSET(0, &rdset))
			{
				memset(buf, 0, sizeof(buf));
				ret = read(STDIN_FILENO, buf, sizeof(buf));
				if(ret == 0)
				{
					//printf("%d\n", ret); ctrl + d
					printf("bye~\n");
					break;
				}
				write(fdw, buf, strlen(buf) - 1);
			}
		}
		else
			printf("I can do other things!\n");
	}
	close(fdr);
	close(fdw);
	return 0;
}
