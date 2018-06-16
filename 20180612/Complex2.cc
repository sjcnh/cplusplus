 ///
 /// @file    Complex2.cc
 /// @author  LJW
 /// @date    2018-06-15 00:11:21
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Complex
{
public:
	Complex(double dreal, double dimag)
	: _dreal(dreal)
	, _dimag(dimag)
	{
		cout << "Complex() " << endl;
	}

	void display()
	{
		cout << _dreal << " + " << _dimag << "i" << endl;
	}

	// 成员函数的形式
	Complex operator+(const Complex &rhs)
	{
		return Complex(_dreal + rhs._dreal,
					   _dimag + rhs._dimag);
	}

private:
	double _dreal;
	double _dimag;

};



// 运算符重载的功能不能指针对于内置类型数据
// 只能作用于自定义类类型和枚举类型
#if 0
int operator+(int x, int y)
{

	return x - y;
}
#endif
int main()
{
	Complex c1(1, 2);
	c1.display();
	Complex c2(3, 4);
	c2.display();
	Complex c3 = c1 + c2;
	c3.display();

	return 0;
}
