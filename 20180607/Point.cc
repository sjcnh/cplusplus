 ///
 /// @file    Point.cc
 /// @author  sjcnh(itechie@163.com)
 /// @date    2018-06-07 10:52:54
 ///
#include <string> 
#include <iostream>
using std::cout;
using std::endl;

class Point
{
	public:
		Point()
		: _ix(0)
		, _iy(0)
		{
			cout << "Point()" << endl;
		}

		Point(int ix, int iy)
		: _ix(ix)
		, _iy(iy)
		{
			cout << "Point(int, int)" << endl;
		}
		void print();

	private:
		int _ix;
		int _iy;

};

void Point::print()
{
	cout << "(" << _ix
		 << "," << _iy
		 << ")" << endl;
}
int main()
{
	Point p1(1, 2);
	
}
