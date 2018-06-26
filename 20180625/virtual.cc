 ///
 /// @file    virtual.cc
 /// @author  LJW
 /// @date    2018-06-25 23:46:48
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Base
{
public:
	virtual void display()
	{
		cout << "Base::display()" << endl;
	}
};

class Base1
: public Base
{
public:
	virtual void display();

};

void Base1::display()
{
	cout << "Base1::display()" << endl;
}

class Derived
: public Base1
{
public:
	virtual void display()
	{
		cout << "Derived::display()" << endl;
	}


};


void fun(Base *ptr)
{
	ptr->display();

}

int main()
{
	Base b;
	Base1 b1;
	Derived d;
	fun(&b);
	fun(&b1);
	fun(&d);

	return 0;
}
