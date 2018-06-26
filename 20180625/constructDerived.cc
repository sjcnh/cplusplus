 ///
 /// @file    constructDerived.cc
 /// @author  LJW
 /// @date    2018-06-25 20:38:12
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Base
{
#if 1   // 基类如果没有定义构造函数，那么会调用默认构造函数
public:
	Base()
	{
		cout << "Base()" << endl;
	}
#endif

};

class Derived
: public Base
{
public:
	Derived(int id)
	: _id(id)
	{
		cout << "Derived(int)" << endl;
	}

private:
	int _id;

};

int main()
{
	Derived d(1);
	 
	return 0;

}
