 ///
 /// @file    struct.cc
 /// @author  sjcnh(itechie@163.com)
 /// @date    2018-06-07 17:40:28
 ///
 
#include <iostream>
#include <vector>
#include <string>
using std::string;
using std::vector;
using std::cout;
using std::endl;

struct Sales 
{
	std::string bookNo;
	unsigned sold{0}; // 花括号， ok！
	//unsigned sold = 0;  拷贝初始化， ok！
	//unsigned sold(0); // 圆括号，no！

};

int main()
{

	vector<string> v1{"a", "b"}; // 列表初始化
	vector<string> v2("a", "b"); // 错误

	return 0;	
}
