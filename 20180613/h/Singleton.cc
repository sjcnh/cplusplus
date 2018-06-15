 ///
 /// @file    Singleton.cc
 /// @author  LJW
 /// @date    2018-06-13 16:59:16
 ///

#include <stdio.h>
#include <iostream>
using std::cout;
using std::endl;

class Singleton
{
public:
	static Singleton * getInstance()
	{
		if(_pInstance == NULL)
		{
			_pInstance = new Singleton();
		}
		return _pInstance;
	}
	
	static void destroy()
	{
		if(_pInstance)
			delete _pInstance;
	}	


private:
	Singleton() {	cout << "Singleton()" << endl; }
	~Singleton() {	cout << "~Singleton()" << endl;	}

private:
	static Singleton * _pInstance;
};

Singleton * Singleton::_pInstance = NULL;
int main()
{
	Singleton * p1 = Singleton::getInstance();
	Singleton * p2 = Singleton::getInstance();

	printf("p1= %p\n", p1);
	printf("p2= %p\n", p2);
	Singleton::destroy();

}
