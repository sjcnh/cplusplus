 ///
 /// @file    Condition.h
 /// @author  LJW
 /// @date    2018-06-13 20:54:26
 ///
#ifndef __MY_CONDITION_H__
#define __MY_CONDITION_H__

#include <pthread.h>

namespace lj
{
class MutexLock; // 类的前向声明，作用：减少头文件的依赖，防止头文件的循环引用

class Condition
{
public:
	Condition(MutexLock &mutex);
	~Condition();

	void wait();
	void notify();
	void notifyAll();

	Condition(const Condition &) = delete;
	Condition & operator=(const Condition &) = delete;

private:
	pthread_cond_t _cond;
	MutexLock &_mutex; // 占据一个指针大小
};

} // end of namespace lj
#endif
