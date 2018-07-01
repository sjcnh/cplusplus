 ///
 /// @file    Point.cc
 /// @author  LJW
 /// @date    2018-06-28 19:48:52
 ///
 
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

int main()
{
	Point p1(1, 2);
	Point p2 = p1;
	p2.print();
	cout << "-----------------" << endl;
	Point p3(3, 5);
	p3 = p1;
	p3.print();


}
