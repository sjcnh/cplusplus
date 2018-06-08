 ///
 /// @file    changeFirst.cc
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
	//string s("hello, World!");
	string s("kkk, World!");
	if(!s.empty())
		s[0] = toupper(s[0]);
	cout << s << endl;

}
