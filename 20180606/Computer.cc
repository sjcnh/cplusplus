 ///
 /// @file    computer.cc
 /// @author  sjcnh(itechie@163.com)
 /// @date    2018-06-06 14:26:06
 ///

#include <string.h>
#include "Computer.h"
#include <iostream>
using std::cout;
using std::endl;


void Computer::setBrand(const char *brand)
{
	strcpy(_brand, brand);
}

void Computer::setPrice(float price)
{
	_price = price;
}

void Computer::print()
{
	cout << "brand:" << _brand << endl;
	cout << "price:" << _price << endl;
}

