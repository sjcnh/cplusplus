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
		// 初始化列表 或者 初始化表达式
		// 初始化列表的顺序
		// 数据成员的初始化与其在初始化表达式中的顺序无关
		// 只与其再被声明时的顺序有关
		/*	
		Point()
		: _iy(0)
		, _ix(_iy)
		{
			cout << "Point()" << endl;
		}
		*/

		Point()
		: _ix(0)
		, _iy(0)
		{
			cout << "Point()" << endl;
		}
		
		Point(int ix)
		: _ix(ix)
		, _iy(999)
		{
			cout << "Point(int)" << endl;
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
	Point p1;
	p1.print();
	Point p2(2,9);
	p2.print();
	Point p3(3);
	p3.print();
	return 0;	
}
