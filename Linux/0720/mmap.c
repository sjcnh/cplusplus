 ///
 /// @file    mmap.c
 /// @author  LJW
 /// @date    2018-07-20 20:39:32
 ///
 
#include "func.h"

int main(int argc, char *argv[])
{
	if(argc != 2)
	{
		printf("error args!\n");
		return -1;
	}
	int fd;
	fd = open(argv[1], O_RDWR);
	if(-1 == fd)
	{
		perror("open");
		return -1;
	}
	char *p;
	p = (char *)mmap(NULL, 4096, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0); 
	if((char *)-1 == p)
	{
		perror("mmap");
		return -1;
	}
	printf("fd = %d\n", fd);
	printf("p = %s\n", p);
	strcpy(p, "hellokitty");
	p = ++p;
	munmap(p, 4096);
	if((char *)-1 == p)
	{
		perror("munmap");
		return -1;
	}

	return 0;
}
