 ///
 /// @file    Point.cc
 /// @author  LJW
 /// @date    2018-06-24 21:12:07
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
		cout << "Point(int ix = 0, int iy = 0)" << endl;
	}

	~Point()
	{
		cout << "~Point()" << endl;
	}
	
protected:
	int _ix;
	int _iy;
};

class Point3D : public Point
{
public:
	Point3D(int ix = 0, int iy = 0, int iz = 0)
	: Point(ix, iy)
	, _iz(iz)
	{
		cout << "Point3D()" << endl;
	}

	~Point3D()
	{
		cout << "~Point3D()" << endl;
	}

	friend std::ostream & operator<<(std::ostream &os, const Point3D &rhs);


private:
	int _iz;

};

std::ostream & operator<<(std::ostream &os, const Point3D &rhs)
{
	os << "(" << rhs.Point::_ix
	   << "," << rhs.Point::_iy
	   << "," << rhs._iz
	   << ")" ;
	return os;
}



int main()
{
	Point3D pt(1, 2, 3);
	cout << pt << endl;

	return 0;

}
