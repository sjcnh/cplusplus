 ///
 /// @file    Singleton.cc
 /// @author  sjcnh(itechie@163.com)
 /// @date    2018-06-08 20:26:01
 ///

#include <stdio.h>
#include <iostream>
using std::cout;
using std::endl;

// 单例模式  Singleton
class Singleton
{
	public:
		static Singleton * getInstance()
		{
			if(NULL == _pInstance)
			{
				_pInstance = new Singleton();
			}
			return _pInstance;// 完成Singleton对象的创建
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
		};

		~Singleton()
		{
			cout << "~Singleton()" << endl;
		}

		static Singleton * _pInstance; // 保存
};

Singleton * Singleton::_pInstance = NULL;
//Singleton s3;
//statict Singleton s4;

int main()
{
	// Singleton s1; // 调用了无参构造函数， 不能让该语句编译通过
	// Singleton s2;
	// 静态成员函数可以不创建对象，通过类名加函数名调用
	Singleton * pSingleton1 = Singleton::getInstance(); // 堆对象
	Singleton * pSingleton2 = Singleton::getInstance(); // 堆对象

	printf("pSingleton1 = %p\n", pSingleton1);
	printf("pSingleton2 = %p\n", pSingleton2);

	Singleton::destroy();
}
