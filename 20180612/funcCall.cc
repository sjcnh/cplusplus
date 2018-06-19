 ///
 /// @file    funcCall.cc
 /// @author  LJW
 /// @date    2018-06-17 14:54:37
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Foo
{

public:
	Foo()
	: _counter(0)
	{}

	// 重载了函数调用运算符的类，创建的对象成为函数对象
	// 函数对象可以拥有自己的状态
	int operator()(int x, int y)
	{
		++_counter;
		return x + y;
	}

	int operator()(int x, int y, int z)
	{
		++_counter;
		return x * y * z;
	}

	int getCounter() const
	{
		return _counter;
	}
	
private:
	int _counter;
};

int test()
{
	Foo foo;
	cout << "1 + 2 = " << foo(1, 2) << endl;  // 函数对象
	cout << "2 * 3 * 5 = " << foo(2, 3, 5) << endl;
	cout << "foo对象调用了" << foo.getCounter() << "次" << endl;
}

int main()
{
	test();

}
