 ///
 /// @file    test.cc
 /// @author  LJW
 /// @date    2018-07-11 23:19:07
 ///
 
#include <typeinfo>
#include <iostream>
using std::cout;
using std::endl;

int main()
{
	auto c = {1, 2};
	cout << typeid(c).name() << endl;
	auto _lambda = [](int x) { return x + 3;	};
	cout << "_lambda: " << _lambda(5) << endl;
	return 0;
}
