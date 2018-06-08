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
	string s("aaa, World!");
	for(decltype(s.size()) idx = 0; idx != s.size() && !isspace(s[idx]); ++idx)
		s[idx] = toupper(s[idx]);
	cout << s << endl;

}
