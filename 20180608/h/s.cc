 ///
 /// @file    s.cc
 /// @author  LJW
 /// @date    2018-06-08 21:02:33
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
			{
				delete _pInstance;
			}
		}

	private:
		Singleton()
		{
			cout << "Singleton()" << endl;
		}

		~Singleton()
		{
			cout << "~Singleton()" << endl;
		}

		static Singleton * _pInstance;
};

Singleton * Singleton::_pInstance = NULL;

int main()
{
	Singleton * pSingleton1 = Singleton::getInstance();
	Singleton * pSingleton2 = Singleton::getInstance();

	if(pSingleton1 == pSingleton2)
	{
		cout << "same address" << endl;
	}

	Singleton::destroy();

	return 0;
}
