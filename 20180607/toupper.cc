 ///
 /// @file    toupper.cc
 /// @author  sjcnh(itechie@163.com)
 /// @date    2018-06-07 16:55:17
 ///
#include <string> 
#include <iostream>
#include <cctype>
using std::cout;
using std::endl;
using std::string;

int main()
{
	string s("Hello, World!");
	for(auto &c : s)
		c = toupper(c);
	cout << s << endl;

}
