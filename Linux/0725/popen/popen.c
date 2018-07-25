 ///
 /// @file    popen.c
 /// @author  LJW
 /// @date    2018-07-25 17:01:34
 ///
 
#include "../func.h"

int main()
{
	FILE *fp;
	fp = popen("./print", "r");
	if(NULL == fp)
	{
		perror("popen");
		return -1;
	}
	char buf[128] = {0};
	fgets(buf, sizeof(buf), fp);
	printf("%s", buf);
	pclose(fp);
	return 0;
}
