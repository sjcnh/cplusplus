 ///
 /// @file    templateSingleton.cc
 /// @author  LJW
 /// @date    2018-06-29 16:00:06
 ///
 
#include <stdio.h>
#include <iostream>
using std::cout;
using std::endl;

class Point
{
public:
	Point(int ix = 0, int iy = 0)
	: _ix(ix)
	, _iy(iy)
	{
		cout << "Point()" << endl;
	}

	void print() const
	{
		cout << "(" << _ix
			 << "," << _iy
			 << ")" << endl;
	}

	~Point()
	{
		cout << "~Point()" << endl;
	}

	Point(const Point &rhs)
	: _ix(rhs._ix)
	, _iy(rhs._iy)
	{
		cout << "Point(const Point &)" << endl;
	}

	Point & operator=(const Point &rhs)
	{
		cout << "Point & operator=(const Point &)" << endl;
		_ix = rhs._ix;
		_iy = rhs._iy;
		return *this;
	}

private:
	int _ix;
	int _iy;
};

template <typename T>
class Singleton
{
	class AutoRelease
	{
	public:
		AutoRelease() {	cout << "AutoRelease()" << endl;	}
		~AutoRelease() 
		{	
			if(_pInstance)
				delete _pInstance;
			cout << "~AutoRelease()" << endl;	
		}
	};

public:
	static T * getInstance()
	{
		if(_pInstance == NULL)
		{
			_auto; // 必须使用以下_auto对象，才可以实现自动释放
			_pInstance = new T();
		}
		return _pInstance;
	}

	static void destroy()
	{
		if(_pInstance)
			delete _pInstance;
	}

private:
	Singleton() {	cout << "Singleton()" << endl;	}
	~Singleton() {	cout << "~Singleton()" << endl;	}
private:
	static AutoRelease _auto;
	static T *_pInstance;
};

template <typename T>
T * Singleton<T>::_pInstance = NULL;
	
template <typename T>
typename Singleton<T>::AutoRelease Singleton<T>::_auto; // 加typename，告知编译器AutoRelease是类类型

int main()
{
	Point *pt1 = Singleton<Point>::getInstance();
	Point *pt2 = Singleton<Point>::getInstance();
	printf("pt1 = %p\n", pt1);
	printf("pt2 = %p\n", pt2);

//	Singleton<Point>::destroy();

	return 0;
}
