 ///
 /// @file    Figure.cc
 /// @author  LJW
 /// @date    2018-06-26 20:22:38
 ///
 
#include <cmath>
#include <iostream>
using std::cout;
using std::endl;

class Figure
{
public:

	virtual void display() const = 0;
	virtual double area() = 0;
};

class Circle
: public Figure
{
public:
	Circle(double radius)
	: _radius(radius)
	{
		cout << "Circle(double)" << endl;
	}

	void display() const
	{
		cout << "Circle";
	}

	double area()
	{
		return PI * _radius * _radius;
	}

private:
	double _radius;
	static double PI;

};

// 静态局部变量的初始化
double Circle::PI = 3.1415926;
// 静态全局变量
static double PI = 1;

class Rectangle
: public Figure
{
public:
	Rectangle(double len, double wid)
	: _length(len)
	, _width(wid)
	{
		cout << "Rectangle(double, double)" << endl;
	}

	void display() const
	{
		cout << "Rectangle";
	}

	double area()
	{
		return _length * _width;
	}

private:
	double _length;
	double _width;
};

class Triangle
: public Figure
{
public:
	Triangle(double a, double b, double c)
	:_a(a), _b(b), _c(c)
	{
		cout << "Triangle(int, int, int)" << endl;
	}

	void display() const
	{
		cout << "Triangle";
	}

	double area()
	{
		double p = (_a + _b + _c) / 2;
		return sqrt(p * (p - _a) * (p - _b) * (p - _c)); 
	}

private:
	double _a;
	double _b;
	double _c;
};

void display(Figure *pfig)
{
	pfig->display();
	cout << "面积是：" << pfig->area() << endl;
}

int main()
{
	Circle c(2);
	Rectangle r(5, 10);
	Triangle t(3, 4, 5);

	display(&c);
	display(&r);
	display(&t);

	return 0;
}
