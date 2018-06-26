 ///
 /// @file    test.cc
 /// @author  LJW
 /// @date    2018-06-25 19:51:56
 ///
 
#include <iostream>
using std::cout;
using std::endl;
void test()
{
	

	// 如果传递过来的是右值，而复制构造函数和移动构造函数
	// 移动构造函数 C++11
	String(String &&rhs)
	: _pstr(rhs._pstr)
	{
		cout << "String(String &&)" << endl;
		rhs._pstr = NULL;
	}

	// 移动赋值运算符函数
	String & operator=(String &&rhs)
	{
		cout << "String & operator=(String &&)" << endl;
		if(this != &rhs)  // 自赋值
		{
			delete [] _pstr;
			_pstr = rhs._pstr;
			rhs._pstr = NULL;
		}
		return *this;
	}
		

}


void test3()
{
	int a = 0;
	int b = 20;
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;

	// std::move本质上来说就是一个强制转换
	b = std::move(a); 

	cout << "move 之后" << endl;
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
}


int main()
{

}
