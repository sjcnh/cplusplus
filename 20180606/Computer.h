 ///
 /// @file    computer.h
 /// @author  sjcnh(itechie@163.com)
 /// @date    2018-06-06 15:48:07
 ///
 
#include <iostream>
#ifndef __COMPUTER_H__
#define __COMPUTER_H__
class Computer
{
	public:
		void setBrand(const char *brand);

		void setPrice(float price);

		void print();

	private:
		char _brand[20];
		float _price;

};

#endif
