 ///
 /// @file    Noncopyable.h
 /// @author  LJW
 /// @date    2018-07-02 21:58:21
 ///
 
#ifndef __LJ_NONCOPYABLE_H__
#define __LJ_NONCOPYABLE_H__

namespace lj
{
class Noncopyable
{
protected:
	Noncopyable(){}
	~Noncopyable(){}
private:
	Noncopyable(const Noncopyable &);
	Noncopyable & operator=(const Noncopyable &);
};
} // end of namespace lj
#endif
