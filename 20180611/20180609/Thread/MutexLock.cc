 ///
 /// @file    MutexLock.cc
 /// @author  LJW
 /// @date    2018-06-13 21:02:27
 ///

#include "MutexLock.h"
#include <iostream>

using namespace lj;

MutexLock::MutexLock()
: _isLocking(false)
{
	pthread_mutex_init(&_mutex, NULL);
}

MutexLock::~MutexLock()
{
	pthread_mutex_destroy(&_mutex);
}

void MutexLock::lock()
{
	pthread_mutex_lock(&_mutex);
	_isLocking = true;
}

void MutexLock::unlock()
{
	pthread_mutex_unlock(&_mutex);
	_isLocking = false;
}
