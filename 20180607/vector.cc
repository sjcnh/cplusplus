 ///
 /// @file    vector.cc
 /// @author  sjcnh(itechie@163.com)
 /// @date    2018-06-07 17:27:21
 ///

#include <string>
#include <vector>
#include <iostream>
using std::cout;
using std::endl;
using std::vector;
using std::string;

int main()
{
	vector<int> ivec;
	vector<vector<string>> file;
	vector<string> articles = {"a", "an", "the"};
	cout << "sizeof(vector<int>)=" << sizeof(ivec) << endl;
	cout << "sizeof(vector<vector<string>>)=" << sizeof(file) << endl;
	cout << "sizeof(vector<string>)=" << sizeof(articles) << endl;
}
