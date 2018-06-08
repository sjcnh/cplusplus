 ///
 /// @file    Computer.cc
 /// @author  sjcnh(itechie@163.com)
 /// @date    2018-06-08 09:27:08
 ///

#include <string>
#include <iostream>
#include <string.h>
using std::cout;
using std::endl;
using std::cin;
using std::string;

class Computer
{
	public:
		Computer()
		: _brand(new char[20])
		, _price(0.0)
		{
			stycpy(_brand, brand);
			cout << "Computer()" << endl;
		}

		Computer(const char * brand, float price)
		: _brand(new char[strlen(brand) + 1]())
		, _price(price)
		{
			cout << "Computer(const char *, float)" << endl;
		}

		Computer(const Computer & rhs)
		: _brand(new char[strlen(rhs._brand) + 1]())
		, _price(rhs._price)
		{
			strcpy(_brand, rhs._brand);
			cout << "Computer(const Computer &)" << endl;
		}			

		Computer & operator= (const Computer & rhs)
		{
			if(this != &rhs)
			{
				delete [] _brand;
				_brand = new char[strlen(rhs._brand) + 1]();
				strcpy(_brand, rhs._brand);
				_price = rhs._price);
			}
			return *this;
		}

		~Computer()
		{
			delete [] _brand;
			_brand = NULL;
			cout << "~Computer()" << endl;
		}

		}


	private:
		char * _brand;
		float _price;
}
int main()
{

}
