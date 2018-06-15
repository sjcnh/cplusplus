 ///
 /// @file    MutexLock.h
 /// @author  LJW
 /// @date    2018-06-13 20:47:07
 ///

#ifndef __MY_MUTEXLOCK_H__
#define __MY_MUTEXLOCK_H__
#include <iostream>
using std::cout;
using std::endl;

namespace lj
{

// 能够进行复制 ---> 值语义
//
class MutexLock
{
public:
	MutexLock();
	~MutexLock();

	void lock();
	void unlock();

	pthread_mutex_t *getMutexLockPtr(){	return &_mutex;}
	// 禁止复制 ---> 对象语义
	MutexLock(const MutexLock &) = delete; //
private:
	MutexLock &operator=(const MutexLock &);


private:
	pthread_mutex_t _mutex;
	bool _isLocking;
};

class MutexLockGuard
{
public:
	MutexLockGuard(MutexLock &mutex)
	: _mutex(mutex)
	{
		_mutex.lock();
	}
	~MutexLockGuard()
	{
		_mutex.unlock();
	}
private:
	MutexLock &_mutex;
};

} // end of namespace lj

#endif
