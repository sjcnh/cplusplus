 ///
 /// @file    PowerWithUnsignedExponent.cc
 /// @author  LJW
 /// @date    2018-07-11 15:15:33
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Solution
{
public:
	double Power(double base, int exponent)
	{
		if(equal(base, 0.0) && exponent < 0)
			return 0.0;
		unsigned int absExponent = (unsigned int)(exponent);
		if(exponent < 0)
			absExponent = (unsigned int)(-exponent);
		//cout << absExponent << endl;
		double ret = PowerWithUnsignedExponent(base, absExponent);
		if(exponent < 0)
			return 1.0 / ret;
		return ret;
	}

	double PowerWithUnsignedExponent(double base, unsigned int exponent)
	{
		if(0 == exponent)
			return 1;
		if(1 == exponent)
			return base;
		double ret = PowerWithUnsignedExponent(base, exponent >> 1);
		ret *= ret;
		if(exponent & 1)
			ret *= base;
		return ret;
	}	

	bool equal(double num1, double num2)
	{
		if((num1 - num2 < 0.0000001) && (num1 - num2 > -0.0000001))
			return true;
		return false;
	}

};

int main()
{
	Solution pow;
	cout << " PowerWithUnsignedExponent (0, 3) " << pow.Power(0, 3) << endl;
	cout << " PowerWithUnsignedExponent (2, 3) " << pow.Power(2, 3) << endl;
	cout << " PowerWithUnsignedExponent (-1, 3) " << pow.Power(-2, 3) << endl;
	cout << " PowerWithUnsignedExponent (-1, 3) " << pow.Power(-2, -3) << endl;

}
