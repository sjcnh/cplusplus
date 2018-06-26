 ///
 /// @file    virtualFunction.cc
 /// @author  LJW
 /// @date    2018-06-26 20:14:36
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class A
{
public:
	virtual void display() = 0;  // 作为接口(功能，服务)存在


};

class B
: public A
{
public:
	// 接口的实习那由派生类完成
	void display()
	{
		cout << "B::display()" << endl;
	}

};


int main()
{
	// 抽象类无法创建对象
	// A a;
	A *pa = new B;

	pa->display();
	B b;

	b.display();

}
