 ///
 /// @file    testComputer.cc
 /// @author  sjcnh(itechie@163.com)
 /// @date    2018-06-06 15:50:47
 ///

#include "Computer.h"
#include <iostream>
using std::cout;
using std::endl;

int main()
{
	Computer com1;
	com1.setBrand("Apple");
	com1.setPrice(9999);
	com1.print();
	return 0;
}
