 ///
 /// @file    Condition.cc
 /// @author  LJW
/// @date    2018-06-13 20:58:46
 ///

#include "Condition.h"
#include "MutexLock.h"

namespace lj
{

Condition::Condition(MutexLock &mutex)
: _mutex(mutex)
{
	pthread_cond_init(&_cond, NULL);
}

Condition::~Condition()
{
	pthread_cond_destroy(&_cond);
}	

void Condition::wait()
{
	pthread_cond_wait(&_cond, _mutex.getMutexLockPtr());
}

void Condition::notify()
{
	pthread_cond_signal(&_cond);
}

void Condition::notifyAll()
{
	pthread_cond_broadcast(&_cond);
}

} // end of namespace lj
