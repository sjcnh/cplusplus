 ///
 /// @file    unique.cc
 /// @author  LJW
 /// @date    2018-06-27 22:42:09
 ///
 
#include <iostream>
#include <memory>
#include <vector>
using std::vector;
using std::cout;
using std::endl;
using std::unique_ptr;


class Point
{
public:
	Point(int ix, int iy)
	: _ix(ix), _iy(iy)
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

private:
	int _ix;
	int _iy;

};

unique_ptr<int> getValue()
{
	unique_ptr<int> up(new int(1));
	return up;
}

int main()
{
	Point *p = new Point(1, 2);
	
	unique_ptr<Point> up(p);
	up->print();

	cout << "p = " << p << endl;
	cout << "up'get() = " << up.get() << endl; // get()返回托管对象的原生”裸指针

	//unique_ptr<Point> up2(up); // 表达对象语义，不能进行赋值或者复制

	unique_ptr<int> pInt = getValue(); // 具有移动语义的移动构造函数
	cout << "*pInt = " << *pInt << endl;

	vector<unique_ptr<int>> vec;
	vec.push_back(std::move(pInt)); // unique_ptr可以作为容器的元素，但必须使用移动语义

	pInt.reset(new int(100)); // unique_ptr 可以调用reset重新托管新的对象
	cout << "*pInt = " << *pInt << endl;
	cout << "...." << endl;	 
	return 0;
}
