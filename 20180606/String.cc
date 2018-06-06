 ///
 /// @file    String.cc
 /// @author  sjcnh(itechie@163.com)
 /// @date    2018-06-06 20:10:41
 ///

/*
 *
 *
 *
 */

#include "String.h"
#include <string.h>
#include <iostream>
using std::cout;
using std::endl;

String::String()
{
	cout << "Stirng()" << endl;
}

String::String(const char *pstr) // 构造函数
{
	cout << "Stirng(const char *pstr)" << endl;
	strcpy(_pstr, pstr);

}
String::String(const String & rhs) // 复制构造函数
{
	

}
//String & operator = (const String & rhs); // 赋值操作符

String::~Stirng() // 析构函数
{

}

void String::print()
{
	cout << _pstr << endl;
}
