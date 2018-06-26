 ///
 /// @file    Figure1.cc
 /// @author  LJW
 /// @date    2018-06-26 20:22:38
 ///
 
#include <cmath>
#include <iostream>
#include <functional>
using std::cout;
using std::endl;

// 具体类  基于对象编程
class Figure
{
public:
	// typedef 
	using DisplayCallback = std::function<void()>;
	using AreaCallback = std::function<double()>;

	// 注册回调函数
	void setDisplayCallback(DisplayCallback && cb)
	{
		_display = std::move(cb); // 
	}

	std::function<void()> display;

	void setAreaCallback(AreaCallback && cb)
	{
		_area = std::move(cb);
	}

	// 执行回调函数  
	void handleDisplayCallback()
	{
		if(_display)
			_display();
	}
	
	double handleAreaCallback()
	{
		if(_area)
			return _area();
		else
			return 0;
	}
private:
	DisplayCallback _display;
	AreaCallback _area;
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

	void show() const
	{
		cout << "Circle";
	}

	double calArea()
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

	void print() const
	{
		cout << "Triangle";
	}

	double getArea()
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
	pfig->handleDisplayCallback();
	cout << "面积是：" << pfig->handleAreaCallback() << endl;
}

int main()
{

	Figure fig;
	Circle c(2);
	Rectangle r(5, 10);
	Triangle t(3, 4, 5);

	// show成员函数, 第一个参数是this，所以可以传递一个对象的引用
	//fig.setDisplayCallback(std::bind(&Circle::show, &c));
	fig.setAreaCallback(std::bind(&Circle::calArea, &c));
	fig.display = std::bind(&Circle::show, &c);
	display(&fig);

	return 0;
}
