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
	double PowerWithUnsignedExponent(double base, unsigned int exponent)
	{
		if(0 == exponent)
			return 1;
		if(0 == base)
			return 0;
		if(1 == exponent)
			return base;
		double ret = PowerWithUnsignedExponent(base, exponent >> 1);
		ret *= ret;
		if(exponent & 1)
			ret *= base;

		return ret;
	}	
};

int main()
{
	Solution pow;
	cout << " PowerWithUnsignedExponent (0, 3) " << pow.PowerWithUnsignedExponent(0, 3) << endl;
	cout << " PowerWithUnsignedExponent (2, 3) " << pow.PowerWithUnsignedExponent(2, 3) << endl;
	cout << " PowerWithUnsignedExponent (-1, 3) " << pow.PowerWithUnsignedExponent(-2, 3) << endl;

}
