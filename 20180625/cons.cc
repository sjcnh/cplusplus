 ///
 /// @file    cons.cc
 /// @author  LJW
 /// @date    2018-06-25 21:47:47
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class A
{
public:
	A()
	{
		cout << "A()" << endl;
		return;
	}
	
	~A()
	{
		cout << "~A()" << endl;
		return;
	}

};

int main()
{
	A a;
	return 0;

}
