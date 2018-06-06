 ///
 /// @file    testString.cc
 /// @author  sjcnh(itechie@163.com)
 /// @date    2018-06-06 20:27:15
 ///

#include <string.h>
#include <iostream>
using std::cout;
using std::endl;

class String
{
	public:
		String();
		String(const char *pstr); // 构造函数
		String(const String & rhs); // 复制构造函数
		String & operator = (const String & rhs) // 赋值操作符
		{
			delete [] _pstr;
			_pstr = new char[strlen(rhs._pstr) + 1]();
			strcpy(_pstr, rhs._pstr);
			cout << "String(const String & rhs)" << endl;
			return *this; // 类外无法使用this指针
		}

		~String();

		void print();

	private:
		char * _pstr;
};

String::String()
: _pstr(new char[10])
{
//	_pstr = new char[10];
	cout << "String()" << endl;
}

String::String(const char *pstr) // 构造函数
: _pstr(new char[strlen(pstr) + 1]())
{
	cout << "String(const char *pstr)" << endl;
	strcpy(_pstr, pstr);

}
String::String(const String & rhs) // 复制构造函数
: _pstr(new char[strlen(rhs._pstr) + 1]())
{
	strcpy(_pstr, rhs._pstr);
	cout << "String(const String &)" << endl;	
}

String::~String() // 析构函数
{// 必须显示提供析构函数
	delete [] _pstr;
	_pstr = NULL;
	cout << "~String()" << endl;
}

void String::print()
{
	cout << _pstr << endl;
}

int main()
{
	String str1;
	String str2 = "hello,world";
	String str3("brand");

	str1.print();
	str2.print();
	str3.print();
	
	String str4 = str3;
	str4.print();

	str4 = str2;
	str4.print();

	return 0;
}
