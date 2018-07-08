///
/// @file    recursive.cc
/// @author  LJW
/// @date    2018-07-07 16:00:01
///
 
#include <iostream>
using std::cout;
using std::endl;
using std::cin;


int AddFrom1toN_Recursiv(int n)
{
	return n <= 0 ? n : n + AddFrom1toN_Recursiv(n - 1);
}

int main()
{

	int n = -1;
	while(cin)
	{
		cin >> n;
		cout << " 1+ ....+ 100 = " << AddFrom1toN_Recursiv(n) << endl;
	}
	return 0;
}

