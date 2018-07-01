 ///
 /// @file    String.cc
 /// @author  LJW
 /// @date    2018-06-17 15:21:41
 ///
#include <cstring> 
#include <iostream>
using std::cout;
using std::endl;

class String
{
public:
	String()
	: _pstr(new char[1]())
	{}

	String(const char * pstr)
	: _pstr(new char[strlen(pstr) + 1]())
	{
		strcpy(_pstr, pstr);
	}


	// 复制构造函数
	String(const String & rhs)
	: _pstr(new char[strlen(rhs._pstr) + 1]())
	{
		strcpy(_pstr, rhs._pstr);	
	}

	~String();

	String & operator=(const String & rhs)
	{
		if(this != &rhs)
		{
			delete [] _pstr;
		
			_pstr = new char[strlen(rhs._pstr) + 1]();
			strcpy(_pstr, rhs._pstr);
		}
		return *this;
	}
	String & operator=(const char *pstr)
	{
		delete [] _pstr;
		_pstr = new char[strlen(pstr) + 1]();
		strcpy(_pstr, pstr);
		return *this;
	}
	String & operator+=(const String &rhs)
	{
		char *tmp = new char[strlen(rhs._pstr) + strlen(_pstr) + 1]();
		strcpy(tmp, _pstr);
		strcat(tmp, rhs._pstr);
		delete []_pstr;
		_pstr = tmp;
		return *this;
	}
		 
	String & operator+=(const char *rhs)
	{
		String tmp(rhs);
		*this += tmp;
		return *this;
	}

	friend String operator+(const String &lhs, const String &rhs);

	friend std::ostream & operator<<(std::ostream &os, const String &rhs);

	char & operator[](std::size_t index)
	{
		static char nullchar = '\0';
		if(index >= strlen(_pstr))
			return nullchar;
		return _pstr[index];
	}

	const char & operator[](std::size_t index) const
	{

	}

	std::size_t size() const
	{
		return ;

	}



	

private:
	char * _pstr;



};

String operator+(const String &lhs, const String &rhs)
{
	String tmp;
	tmp += lhs;
	tmp += rhs;
	return tmp;
}

std::ostream & operator<<(std::ostream &os, const String &rhs)
{ 
	os << rhs._pstr;
	return os;
}

int main()
{

}
