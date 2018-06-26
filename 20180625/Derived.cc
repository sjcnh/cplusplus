 ///
 /// @file    Derived.cc
 /// @author  LJW
 /// @date    2018-06-25 15:53:09
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Base
{
public:
	Base()
	{	cout << "Base()" << endl;	}

	~Base()
	{	cout << "~Base()" << endl;	}

};

class Derived
: Base
{
public:
	Derived()
	{	cout << "Derived()" << endl;	}

	~Derived()
	{	cout << "~Derived()" << endl;	}
};


int main()
{
	Derived d;
	
	return 0;

}
