 ///
 /// @file    Point.cc
 /// @author  sjcnh(itechie@163.com)
 /// @date    2018-06-06 15:42:05
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Point
{
	public:
		Point()
		{
			cout << "Point()" << endl;
			_ix = 0;
			_iy = 0;
		}
		
		Point(int ix)
		{
			cout << "Point()" << endl;
			_ix = ix;
			_iy = 999;
		}

		Point(int ix, int iy)
		{
			cout << "Point()" << endl;
			_ix = ix;
			_iy = iy;
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
	Point p1;
	p1.print();
	Point p2(2,9);
	p2.print();
	Point p3(3);
	p3.print();
	return 0;	
}
