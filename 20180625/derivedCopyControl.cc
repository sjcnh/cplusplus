 ///
 /// @file    derivedCopyControl.cc
 /// @author  LJW
 /// @date    2018-06-25 21:29:36
 ///
 
#include <string.h>
#include <iostream>
using std::cout;
using std::endl;

class Base
{
public:

	Base()
	{}

	Base(const char *pdata)
	: _pData(new char[strlen(pdata) + 1]())
	{
		cout << "Base(const char *)" << endl;
		strcpy(_pData, pdata);
	}

	Base(const Base &rhs)  // 拷贝构造函数
	: _pData(new char[strlen(rhs._pData) + 1]())
	{
		cout << "Base(const Base &)" << endl;
		strcpy(_pData, rhs._pData);
	}

	Base & operator=(const Base &rhs)
	{
		cout << " Base & operator=(const Base &)" << endl;
		if(this != &rhs)
		{
			delete [] _pData;
			_pData = new char[strlen(rhs._pData) + 1]();
			strcpy(_pData, rhs._pData);
		}
		return *this;
	}

	~Base()
	{
//		delete [] _pData;
		cout << "~Base()" << endl;
	}

	friend std::ostream & operator<<(std::ostream &os, const Base &rhs);

private:
	char * _pData;
};

std::ostream & operator<<(std::ostream &os, const Base &rhs)
{
	os << rhs._pData;
	return os;
}

class Derived
: public Base
{
public:
	Derived()
	{}

	Derived(const char *pdata)
	: Base(pdata)
	{
		cout << "Derived(const char *)" << endl;
	}

	~Derived()
	{
		cout <<	"~Derived()" << endl;
	}
	
};

int main()
{
	Derived d;

	return 0;

}
