 ///
 /// @file    Thread.h
 /// @author  LJW
 /// @date    2018-07-02 21:17:11
 ///
 
#ifndef __LJ_THREAD_H_
#define __LJ_THREAD_H_

#include "Noncopyable.h"
#include <pthread.h>

namespace lj
{
class Thread
: Noncopyable // 表达语义的
{
public:
	Thread();
	virtual ~Thread();

	void start();
	void join();

	bool isRunning() const {	return _isRunning;	}
private:
	virtual void run() = 0; // 就是线程要执行的任务
	
	static void *threadFunc(void *);
private:
	pthread_t _pthid;
	bool _isRunning;
};


}// end of namespace lj
#endif
