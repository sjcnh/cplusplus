 ///
 /// @file    Point.cc
 /// @author  LJW
 /// @date    2018-06-14 22:54:21
 ///

#include <cmath>
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

	int getX() const {	return _ix;	}
	int getY() const {	return _iy;	}

private:
	int _ix;
	int _iy;
};

float distance(const Point &lhs, const Point &rhs)
{
	return sqrt(pow(2, (lhs.getX() -rhs.getX())) + pow(2, (lhs.getY() - rhs.getY())));
}

int main()
{
	Point p1(1, 2);
	Point p2(3, 4);
	cout << "distance between and is " << distance(p1, p2) << endl;
	return 0;

}
