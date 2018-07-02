 ///
 /// @file    figure1.cc
 /// @author  LJW
 /// @date    2018-06-26 20:22:38
 ///
 
#include <cmath>
#include <iostream>
#include <memory>
using std::unique_ptr;
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

// 简单工厂模式
// 静态工厂方法
// 缺陷： 新的图形需要修改原类
// 1. 违反开闭原则
// 2. 单一职责原则
//

class Factory
{
public:
	virtual Figure *create() = 0;
	// 动态析构派生类对象
	virtual ~Factory(){}
};

// 具体工厂创建具体的类
class CircleFactory
: public Factory
{
public:
	Figure *create()
	{
		// 
		// load xml
		// ....
		//
		//
		Figure *fig = new Circle(5);
		return fig;
	}

};

class RectangleFactory
: public Factory
{
public:
	Figure *create()
	{
		// 
		// load xml
		// ....
		//
		Figure *fig = new Rectangle(10, 5);
		return fig;
	}
};

class TriangleFactory
: public Factory
{
public:
	Figure *create()
	{
		// 
		// load xml
		// ....
		//
		Figure *fig = new Triangle(3, 4, 5);
		return fig;
	}
};


int main()
{
	// 如果创建的时一个简单对象，根本就没有必要使用工厂模式
	//
	// 只有复杂对象或者是要批量创建对象时，才考虑工厂模式
	//
	// Factory * circleFactory = new CircleFactory();
	// Figure * circle = circleFactory->create();
	// 
	unique_ptr<Factory> circleFactory(new CircleFactory());
	unique_ptr<Figure>  circle(circleFactory->create());

	unique_ptr<Factory> rectangleFactory(new RectangleFactory());
	unique_ptr<Figure> rectangle(rectangleFactory->create());

	unique_ptr<Factory> triangleFactory(new TriangleFactory());
	unique_ptr<Figure> triganle(triangleFactory->create());

	display(circle.get());
	display(rectangle.get());
	display(triganle.get());

	return 0;
}
