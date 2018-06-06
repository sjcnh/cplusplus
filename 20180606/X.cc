 ///
 /// @file    X.cc
 /// @author  sjcnh(itechie@163.com)
 /// @date    2018-06-06 15:31:32
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Point
{
public:
	Point()
	: _ix(0) // 初始化列表
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
	Point p;
	p.print();
	Point p1(1,99);
	p1.print();

}
