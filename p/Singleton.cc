 ///
 /// @file    Singleton.cc
 /// @author  LJW
 /// @date    2018-07-03 20:50:37
 ///
 
#include <iostream>
#include <cstdio>
using std::cout;
using std::endl;

class Singleton
{
public:
	static Singleton * getInstance()
	{
		if(_pInstance == NULL)
			_pInstance = new Singleton();

		return _pInstance;
	}

	static void destroy()
	{
		if(_pInstance)
			delete _pInstance;
	}


private:
	Singleton()	{	cout << "Singleton()" << endl;	}
	~Singleton() {	cout << "~Singleton()" << endl;	}
	static Singleton * _pInstance;
};

Singleton * Singleton::_pInstance = NULL;


int main()
{
	Singleton *p1 = Singleton::getInstance();
	Singleton *p2 = Singleton::getInstance();
	Singleton *p3 = Singleton::getInstance();
	printf("p's address = %p\n", p1);
	printf("p's address = %p\n", p2);
	printf("p's address = %p\n", p3);

	Singleton::destroy();

}
