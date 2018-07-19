 ///
 /// @file    Orphan.cc
 /// @author  LJW
 /// @date    2018-07-09 19:57:02
 ///
 
#include "func.h"
#include <iostream>
#include <pthread.h>
using std::cout;
using std::endl;

int main()
{
	pid_t pid = fork();
	if(0 == pid)
		cout << "child pid = " << getpid() << " ppid = " << getppid() << endl;
	else
		cout << "parent pid = " << getpid() << " ppid = " << getppid() << endl;

	return 0;
}
