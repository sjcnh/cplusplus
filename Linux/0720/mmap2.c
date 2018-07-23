 ///
 /// @file    mmap2.c
 /// @author  LJW
 /// @date    2018-07-20 21:31:24
 ///
 
#include "func.h"

int main()
{
	// 打开一个文件
	int fd = open("virtualTable.cc", O_RDWR);
	// 获取一个文件的大小
	int len = lseek(fd, 0, SEEK_END);
	// 创建内存映射区
	void *ptr = mmap(NULL, len, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
	if(ptr == MAP_FAILED)
	{
		perror("mmap");
		return -1;
	}
	printf("%s", (char *)ptr);
	
	// 释放映射区
	munmap(ptr, len);
	// 关闭文件
	close(fd);

	return 0;
}
