 ///
 /// @file    testThread.cc
 /// @author  LJW
 /// @date    2018-07-02 21:26:12
 ///
 
#include "Thread.h"
#include <unistd.h>
#include <iostream>
using std::cout;
using std::endl;

struct MyTask
{
	void run()
	{
		::srand(::time(NULL));
		int cnt = 10;
		while(cnt--)
		{
			int number = ::rand() % 100;
			cout << " >> Thread: " << pthread_self() << " get a number:" << number << endl;
			::sleep(1);
		}
	}
};

int main()
{
	cout << "MainThread: " << pthread_self() << endl;
	lj::Thread myThread(std::bind(&MyTask::run, MyTask()));
	myThread.start();
	myThread.join();
	
	return 0;
}
