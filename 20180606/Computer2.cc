 ///
 /// @file    Computer2.cc
 /// @author  sjcnh(itechie@163.com)
 /// @date    2018-06-06 17:04:33
 ///
#include <string.h>
#include <iostream>
using std::cout;
using std::endl;

class Computer
{
	public: // 接口  服务
		// 成员函数（方法）
		void setBrand(const char *brand);

		void setPrice(float price);

		void print();

		Computer()
		: _brand("new")
		, _price(1111)
		{
			cout << "Computer()" << endl;
		}

	private: // 封装
		// 数据成员
		char _brand[20];
		float _price;

};
void Computer::setBrand(const char * brand)
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

	
int main()
{
	Computer com1;
	com1.setBrand("Apple");
	com1.setPrice(9999);
	com1.print();

	Computer com;
	com.print();
	return 0;
}
