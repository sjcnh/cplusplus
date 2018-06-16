 //
 /// @file    Complex1.cc
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
		if(_dreal == 0 && _dimag != 0)
			cout << _dimag << "i" << endl;
		else{
			cout << _dreal;
			if(_dimag > 0)
				cout << " + " << _dimag << "i"	<< endl;
			else if(_dimag < 0)
				cout << " - " << (_dimag * -1) << "i" << endl;
			else
				cout << endl;
		}
	}
	friend Complex operator+(const Complex &lhs, const Complex &rhs);
	 
	// 复合赋值运算符推荐以成员函数的形式进行重载
	Complex & operator+=(const Complex &rhs)
	{
		_dreal += rhs._dreal;
		_dimag += rhs._dimag;
		return *this;
	}
	friend bool operator<(const Complex &lhs, const Complex &rhs);

	// 前置++ 效率更高
	Complex & operator++()
	{
		++_dreal;
		++_dimag;
		return *this;
	}
	// 后置++没有&，因为是先调用！
	Complex operator++(int) // int为了与前置++进行区分，是一个标志位
	{
		Complex tmp(*this);
		++_dreal;
		++_dimag;
		return tmp;
	}


private:
	double _dreal;
	double _dimag;

};


// 以友元函数 在类内进行声明
Complex operator+(const Complex &lhs, const Complex &rhs)
{
#if 0
	return Complex(lhs._dreal + rhs._dreal, 
				   lhs._dimag + rhs._dimag);
#endif 
	Complex temp(lhs);
	temp += rhs;
	return temp;
}

bool operator<(const Complex &lhs, const Complex &rhs)
{
	return lhs._dreal < rhs._dreal;
}
// 运算符重载的功能不能指针对于内置类型数据
// 只能作用于自定义类类型和枚举类型
#if 0
int operator+(int x, int y)
{

	return x - y;
}
#endif
int test()
{
	Complex c1(1, 2);
	c1.display();
	Complex c2(3, 4);
	c2.display();
	Complex c3 = c1 + c2;
	c3.display();
	Complex c4(0, 0);
	Complex c5(1, -1);
	Complex c6 = c4 + c5;
	c6.display();
	return 0;
}

int test1()
{
	int a = 4, b = 3;
	a += b; // a = a + b; 如果a发生变化，一般设计为成员函数形式的重载

	Complex c1(1, -1);
	Complex c2(3, 4);
	if(c1 < c2)
		cout << " c1 < c2" << endl;

	return 0;

}

int test2()
{
	int a = 3;
	++a; // 前置++
	a++; // 后置++

	Complex c1(1, 2);
	c1.display();
	++c1;
	c1.display();
	

	return 0;
}

int main()
{
	//test();
	//test1();
	test2();
	return 0;
}
