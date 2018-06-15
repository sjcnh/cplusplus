 ///
 /// @file    addTemplate.cc
 /// @author  LJW
 /// @date    2018-06-14 20:10:24
 ///
 
#include <string.h>
#include <iostream>
using std::cout;
using std::endl;
// 模板 --> 类型参数化 --> 代码生成器
//          实例化（模板参数推导)
// 函数模板 --->  模板函数
// 
// <> 模板参数列表
//	1.使用class 或者时typename设置类型参数
//	2.非类型参数，就是常量表达式（整型数据）
//
template <class T>
T add(T x, T y)
{
	cout << "T add(T, T)" << endl;
	return x + y;
}
// 模板的特化版本， 不能独立于通用版本
template <>
const char * add<const char *>(const char * lhs, const char *rhs)
{
	char *ptmp = new char[strlen(lhs) + strlen(rhs) + 1]();
	strcpy(ptmp, lhs);
	strcat(ptmp, rhs);
	return ptmp;
}

int add(int x, int y)
{
	cout << "int add(int, int)" << endl;
	return x + y;
}

// 关于重载：
// 函数模板与函数模板之间可以进行重载
// 普通函数与函数模板之间可以进行重载
//
//C++11 之后，非类型参数可以设置默认值：
template <typename T, int kNum = 10>
T func(T x, T y)
{
	return x * y * kNum;
}


// 函数模板的声明
template <typename T>
T add(T x, T y, T z);

int main()
{
	int a = 1, b = 3;
	double d1 = 1.1, d2 = 2.2;
	const char *p1 = "hello";
	const char *p2 = "world";
	cout << add(p1, p2) << endl;

	//隐式实例化
	cout << "a + b = " << add(a, b) << endl;

	//显示实例化
	cout << "d1 + d2 = " << add<double>(d1, d2) << endl;

	// 常量传递的方式
	cout << func<int, 20>(a, b) << endl;

}

// 函数模板的实现：
template <typename T>
T add(T x, T y, T z)
{
	return x + y + z;
}
