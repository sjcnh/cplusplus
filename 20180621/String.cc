 ///
 /// @file    String.cc
 /// @author  LJW
 /// @date    2018-06-28 21:12:35
 ///
 
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <vector>
using std::vector;
using std::cout;
using std::endl;


class String
{
public:
	String()
	{
		cout << "String()" << endl;
	}
	
	String(const char *pstr)
	:_pstr(new char[strlen(pstr) + 1]())
	{
		cout << "String(const char *)" << endl;
		strcpy(_pstr, pstr);
	}

	// 拷贝构造函数
	String(const String &rhs)
	: _pstr(new char[strlen(rhs._pstr) + 1]())
	{
		cout << "String(const String &)" << endl;
		strcpy(_pstr, rhs._pstr);
	}

	// 移动拷贝构造函数 C++11
	String(String &&rhs)
	: _pstr(rhs._pstr)
	{
		cout << "String &&" << endl;
		rhs._pstr = NULL;
	}

	// 赋值运算符函数
	String & operator=(const String &rhs)
	{
		cout << "String & operator=(const String&)" << endl;
		if(this != &rhs)
		{
			delete [] _pstr;
			_pstr = new char[strlen(rhs._pstr) + 1]();
			strcpy(_pstr, rhs._pstr);
		}
		return *this;
	}

	// 移动赋值运算符函数
	String & operator=(String &&rhs)
	{
		cout << "String & operator=(String &&rhs)" << endl;
		if(this != &rhs)
		{
			// 回收自己的空间
			delete [] _pstr;
			// 指向临时对象的空间
			_pstr = rhs._pstr;
			// 临时对象的指针置空，回收销毁时不会影响到赋值对象的空间
			rhs._pstr = NULL;
		}
		return *this;
	}

	~String()
	{
		cout << "~String()" << endl;
	}

	const char * c_str() const
	{
		return _pstr;
	}

	friend std::ostream & operator<<(std::ostream &os, const String &rhs);

private:
	char * _pstr;
};

std::ostream & operator<<(std::ostream &os, const String &rhs)
{
	os << rhs._pstr;
	return os;
}

int main()
{
	vector<String> vec;
	vec.push_back(String("hello"));
	cout << "----------------" << endl;
	String s1("hello,world");
	cout << "----------------" << endl;
	s1 = String("kkkk");
	printf("s1 address = %p\n", s1.c_str()); 
	cout << "s1 = " << s1 << endl;
	String s2 = std::move(s1);
	cout << "s2 = " << s2 << endl;
	cout << "s1 = " << s1 << endl;
	printf("s2 address = %p\n", s2.c_str()); 
	cout << endl;

	return 0;
}
