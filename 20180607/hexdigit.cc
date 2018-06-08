 ///
 /// @file    hexdigit.cc
 /// @author  sjcnh(itechie@163.com)
 /// @date    2018-06-07 17:17:54
 ///
#include <string>

#include <iostream>
using std::cout;
using std::endl;
using std::string;
using std::cin;

int main()
{
	const string hexdigits = "0123456789ABCDEF";
	cout << "Enter  a series of num between 0 and 15"
		 << " separated by spaces. Hit ENTER when you finished: "
		 << endl;

	string result;
	string::size_type n;
	string::size_type max = 50;
	while(cin >> n)
		if(n < hexdigits.size())
			result += hexdigits[n];
	cout << "the result is " << result << endl;
}
