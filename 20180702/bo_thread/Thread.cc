 ///
 /// @file    Thread.cc
 /// @author  LJW
 /// @date    2018-07-02 21:21:08
 ///
 
#include "Thread.h"
#include <iostream>
using std::cout;
using std::endl;
using namespace lj;

Thread::Thread(ThreadCallBack && cb)
: _pthid(0)
, _isRunning(false)
, _cb(std::move(cb))
{}

void Thread::start()
{
	pthread_create(&_pthid, NULL, threadFunc, this);
	_isRunning = true;
}

void * Thread::threadFunc(void *arg)
{
	Thread *pthread = static_cast<Thread*>(arg);
	if(pthread)
		pthread->_cb(); // 执行任务, 回调函数

	return NULL;
}

void Thread::join()
{
	pthread_join(_pthid, NULL);
	_isRunning = false;
}

Thread::~Thread()
{
	if(_isRunning)
	{
		pthread_detach(_pthid); // 将运行的线程交给系统进行托管
		_isRunning = false;
	}
}

