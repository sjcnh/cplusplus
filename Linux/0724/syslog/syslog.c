 ///
 /// @file    syslog.c
 /// @author  LJW
 /// @date    2018-07-24 15:55:20
 ///
 
#include <syslog.h>

int main()
{
	syslog(LOG_INFO, "I am log %d\n", 125);
	return 0;
}
