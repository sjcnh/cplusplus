 ///
 /// @file    RAII.cc
 /// @author  LJW
 /// @date    2018-06-26 23:40:32
 ///
 
#include <memory>
#include <iostream>
using std::cout;
using std::endl;
using std::auto_ptr;

template <typename T>
class RAII
{

public:
	RAII(T *pdata)
	: _pdata(pdata)
	{}

	T * operator->()
	{
		return _pdata;
	}


	T & operator*()
	{
		return *_pdata;
	}


	~RAII()
	{
		if(_pdata)
			delete _pdata;
	}

private:
	T *_pdata;
};

class Point
{
public:
	Point(int ix, int iy)
	: _ix(ix), _iy(iy)
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

private:
	int _ix;
	int _iy;

};

int main()
{
	//int *pInt = new int(1);
	//cout << "*pInt = " << *pInt << endl;
	RAII<int> pInt(new int(1));
	cout << "*pInt = " << *pInt << endl;	

	RAII<Point> pPoint(new Point(1, 2));
	pPoint->print();

	std::auto_ptr<Point> pt(new Point(3, 4));
	pt->print();

}
