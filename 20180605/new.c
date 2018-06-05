 ///
 /// @file    new.c
 /// @author  sjcnh(itechie@163.com)
 /// @date    2018-06-05 15:52:17
 ///
 
#include <iostream>
using std::cout;
using std::endl;

int main()
{
	int *p = new int(101);
	cout << "*p = " << *p << endl;
	delete p;
	return 0;
}
