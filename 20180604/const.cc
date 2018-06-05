 ///
 /// @file    const.cc
 /// @author  sjcnh(itechie@163.com)
 /// @date    2018-06-04 21:10:30
 ///
 
#include <iostream>
using std::cout;
using std::endl;

// 定义一个常量
#define MAX 100

int main()
{
	int a = 1;
	const int b = 10;
	//b = 20;
	cout << a * MAX << endl;
	cout << b * MAX << endl;

	return 0;
}
