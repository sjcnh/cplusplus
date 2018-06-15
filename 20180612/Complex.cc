 ///
 /// @file    Complex.cc
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

private:
	double _dreal;
	double _dimag;

};

int main()
{
	Complex c1(1,2);
	c1.display();
}
