 ///
 /// @file    vectorAdd.cc
 /// @author  sjcnh(itechie@163.com)
 /// @date    2018-06-07 20:22:45
 ///

#include <cstring>
#include <string.h>
#include <string>
#include <vector>
#include <iostream>
using std::cout;
using std::endl;
using std::cin;
using std::vector;
using std::string;
using std::strcmp;

int main()
{
	string word;
	vector<string> text;
	cin >> word;	
	text.push_back(word);

	//while(cin >> word)
	//{
	//	text.push_back(word);
	//}
	for(decltype(text.size()) idx = 0; idx != text.size(); ++idx)
	{
		cout << text[idx] << endl;
	}
	return 0;
}
