 ///
 /// @file    String.h
 /// @author  sjcnh(itechie@163.com)
 /// @date    2018-06-06 20:15:44
 ///
#ifndef __STRING_H__
#define __STRING_H__

#include <iostream>
class Stirng
{
	public:
		String();
		String(const char *pstr); // 构造函数
		String(const String & rhs); // 复制构造函数
		String & operator = (const String & rhs); // 赋值操作符
		~Stirng();

		void print();

	private:
		char * _pstr;
};

#endif
