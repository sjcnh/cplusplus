 ///
 /// @file    templateAdd.cc
 /// @author  LJW
 /// @date    2018-06-14 15:45:37
 ///
 
#include <iostream>
using std::cout;
using std::endl;
//模板参数列表
//1.类型参数
//2.非类型参数
template <typename T>
T add(T a, T b)
{
	return a + b;
}

template <class T, int kNum = 10>
T func(T a, T b)
{
	return a * b * kNum;
}

int add(int x, int y)
{
	return x + y;
}

int main()
{
	int a = 3, b = 1;
	double d1 = 1.1, d2 = 3.3;
	char ch1 = 'a', ch2 = 2;

	cout << "int " << add(a, b) << endl;
	cout << "double 显示" << add<double>(d1, d2) << endl;
	cout << "char " << add(ch1, ch2) << endl;

	cout << "func()" << func(a, b) << endl;
	//C++11 之前需要显示给出非类型参数，而且不支持默认的非类型参数
//	cout << "func()" << func<int, 30>(a, b) << endl;

	return 0;
}
