 ///
 /// @file    string.cc
 /// @author  sjcnh(itechie@163.com)
 /// @date    2018-06-07 15:39:31
 ///
#include <string> 
#include <iostream>
using std::cout;
using std::endl;
using std::cin;
using std::string;

void test()
{
	string word;
	while(cin >> word)
	{
		cout << word << endl;
	}

}

void test1()
{
	string line;
	while(getline(cin, line))
	{
		if(!line.empty())
		{
			cout << line << endl;
		}
	}
}

void test2()
{
	string line;
	while(getline(cin, line))
	{
		auto len = line.size(); // auto 自动类型推断 （size_type类型）

		if(len > 20)
		{
			cout << line << endl;
		}
	}
}

int main()
{
	test2();
	return 0;

}
