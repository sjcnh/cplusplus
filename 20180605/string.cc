 ///
 /// @file    string.cc
 /// @author  sjcnh(itechie@163.com)
 /// @date    2018-06-05 20:21:28
 ///
#include <string> 
#include <iostream>
#include <string.h>
#include <stdlib.h>

using std::cout;
using std::endl;
using std::string;

int test0()
{
	// 字符数组表达字符串
	// char * 指针
	char str1[10] = "hello";
	char str2[] = ",world";
	const char *str3 = "hello,world";// c风格字符串const char *

	int len = strlen(str1) + strlen(str2) + 1;
	char * pstr = (char *)malloc(len);
	memset(pstr, 0, len);
	strcpy(pstr, str1);
	strcat(pstr, str2);
	cout << "pstr = " << pstr << endl;

	free(pstr);
}

void test1()
{
	// c++风格的字符串
	string s1 = "hello"; // 将c风格字符串转换成c++风格的字符串
	string s2 = ",world";
	// 拼接字符串
	string s3 = s1 + s2;
	cout << "s3 = " << s3 << endl;

	string s4 = s1 + ",world";
	cout << "s4 = " << s4 << endl;

	string s5 = "test" + s1;
	cout << "s5 = " << s5 << endl;

	string s6 = s1 + 'a';
	cout << "s6 = " << s6 << endl;

	string s7 = s1.append(",world");
	cout << "s7 = " << s7 << endl;

	string s8 = s1.append(s2);
	cout << "s8 = " << s8 << endl;

	// 获取字符串的长度
	cout << "s1.size = " << s1.size() << endl;
	cout << "s1.length = " << s1.length() << endl;
	
	// 使用数组的方式遍历c++风格字符串
	for(size_t idx = 0; idx != s1.size(); ++idx)
	{
		cout << s1[idx] << "\n";
	}
	cout << endl << endl;

	// c++11标准提出的遍历方式
	for(auto & ch : s1)
	{
		cout << ch << "\n";
	}

	// 截取子串
	string s9 = s1.substr(0, 5);
	cout << "s9 = " << s9 << endl;
	
	string s10 = "world";
	cout << (s9 != s10) << endl;

	// 将C++风格字符串转换成C风格字符串
	const char *pstr = s10.c_str();
	//pstr = s10.data();
	cout << "pstr = " << pstr << endl;
}

int main()
{
//	test0();
	test1();
	return 0;
}
