 ///
 /// @file    Thread.h
 /// @author  LJW
 /// @date    2018-07-02 21:17:11
 ///
 
#ifndef __LJ_THREAD_H_
#define __LJ_THREAD_H_

#include "Noncopyable.h"
#include <pthread.h>
#include <functional>
using std::function;

namespace lj
{
class Thread
: Noncopyable // 表达语义的
{
	using ThreadCallBack = function<void()>;
public:
	Thread(ThreadCallBack && cb);
	~Thread();

	void start();
	void join();

	bool isRunning() const {	return _isRunning;	}
private:
	static void *threadFunc(void *);
private:
	pthread_t _pthid;
	bool _isRunning;
	ThreadCallBack _cb;
};


}// end of namespace lj
#endif
