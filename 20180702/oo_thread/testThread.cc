 ///
 /// @file    testThread.cc
 /// @author  LJW
 /// @date    2018-07-02 21:26:12
 ///
 
#include "Thread.h"
#include <unistd.h>
#include <memory>
#include <iostream>
using std::cout;
using std::endl;
using std::unique_ptr;

class MyThread
: public lj::Thread
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
	unique_ptr<lj::Thread> myThread(new MyThread()); // 线程对象在主线程
	myThread->start();
	myThread->join();
	
	MyThread t1;
//	MyThread t2(t1); // 派生类对象间的复制控制

	return 0;
}
