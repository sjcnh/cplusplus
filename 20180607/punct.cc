 ///
 /// @file    punct.cc
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
	decltype(s.size()) punct_cnt = 0;
	for(auto c : s)
		if(ispunct(c))
			++punct_cnt;
	cout << punct_cnt
		 << " punctuation characters in " << s << endl;

}
