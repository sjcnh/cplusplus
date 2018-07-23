 ///
 /// @file    dup.c
 /// @author  LJW
 /// @date    2018-07-19 16:28:20
 ///
 
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define FILENAME1 "./a.txt"

int main(int argc, char *argv[])
{
	char buf[32] = {0};
	int fd = open(argv[1], O_RDWR);
	if(-1 == fd)
	{
		perror("open");
		return -1;
	}
	
	printf("fd = %d\n", fd);
	int fd1 = dup(fd);
	printf("fd1 = %d\n", fd1);
	int fd2 = dup2(fd, 1);
	printf("fd1 = %d\n", fd1);
	printf("fd2 = %d\n", fd2);

	//read(fd, buf, 4);
	//puts(buf);
	//close(fd);
	//printf("fd = %d\n", fd);
	//lseek(fd1, 0, SEEK_SET);

	printf("test");
	printf("test\n");
	//printf("test %d", fd1);
	//printf("fd1sdfs = %d\n", fd1);
	//read(fd1, buf, sizeof(buf));
	//puts(buf);
	close(fd1);
	return 0;

}
