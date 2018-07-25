 ///
 /// @file    time.c
 /// @author  LJW
 /// @date    2018-07-24 16:05:18
 ///
 
#include "func.h"

int main()
{
	time_t t;
	time(&t);
	struct tm *p;
	p = gmtime(&t);
	printf("%04d-%02d-%02d\n", 1900 + p->tm_year
			, 1 + p->tm_mon, p->tm_mday);
	//printf("wday = %d\n", p->tm_wday);
	printf("今年是%04d年的第%d天\n", 1900 + p->tm_year, 1 + p->tm_yday);

	return 0;

}
