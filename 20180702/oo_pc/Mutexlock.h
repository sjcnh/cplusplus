 ///
 /// @file    Mutexlock.h
 /// @author  LJW
 /// @date    2018-07-02 23:15:07
 ///
 

#ifndef __LJ_MUTEXLOCK_H__
#define __LJ_MUTEXLOCK_H__

#include "Noncopyable.h"
#include <pthread.h>

namespace lj
{
class MutexLock
: Noncopyable
{
public:
	MutexLock()
	{	pthread_mutex_init(&_mutex, NULL);	}

	~MutexLock()
	{	pthread_mutex_destroy(&_mutex);	}

	void lock()
	{	pthread_mutex_lock(&_mutex);	}

	void unlock()
	{	pthread_mutex_unlock(&_mutex);	}
	
	pthread_mutex_t *getMutexLockPtr()
	{	return &_mutex;	}

private:
	pthread_mutex_t _mutex;

};

// RAII
class MutexLockGuard
{
public:
	MutexLockGuard(MutexLock &mutex)
	: _mutex(mutex)
	{	_mutex.lock();	}

	~MutexLockGuard()
	{	_mutex.unlock();	}

private:
	MutexLock &_mutex;
};



} // end of namespace lj

#endif
