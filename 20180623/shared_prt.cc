 ///
 /// @file    shared_ptr.cc
 /// @author  LJW
 /// @date    2018-06-27 22:42:09
 ///
 
#include <iostream>
#include <memory>
#include <vector>
using std::vector;
using std::cout;
using std::endl;
using std::shared_ptr;


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

shared_ptr<int> getValue()
{
	shared_ptr<int> up(new int(1));
	return up;
}

int main()
{
	Point *p = new Point(1, 2);
	
	shared_ptr<Point> up(p);
	up->print();
	cout << "p = " << p << endl;
	cout << "up'get() = " << up.get() << endl; // get()返回托管对象的原生”裸指针

	shared_ptr<Point> up2(up); // 表达复制语义

#if 0
	shared_ptr<int> pInt = getValue(); // 具有移动语义的移动构造函数
	cout << "*pInt = " << *pInt << endl;

	vector<shared_ptr<int>> vec;
	vec.push_back(std::move(pInt)); // shared_ptr可以作为容器的元素，但必须使用移动语义

	pInt.reset(new int(100)); // shared_ptr 可以调用reset重新托管新的对象
	cout << "*pInt = " << *pInt << endl;
	cout << "...." << endl;	 
#endif

	return 0;
}
