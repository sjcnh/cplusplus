 ///
 /// @file    set.cc
 /// @author  LJW
 /// @date    2018-06-19 21:34:05
 ///
#include <cmath>
#include <string>
#include <set>
#include <utility>
#include <iostream>
using std::cout;
using std::endl;
using std::set;
using std::pair;
using std::string;


class Point
{
public:
	Point(int ix = 0, int iy = 0)
	: _ix(ix)
	, _iy(iy)
	{
		cout << "Point(int, int)" << endl;
	}
	float distance() const
	{
		return sqrt(_ix * _ix + _iy * _iy);
	}

	friend std::ostream & operator<<(std::ostream &os, const Point &rhs);

private:
	int _ix;
	int _iy;

};

std::ostream & operator<<(std::ostream &os, const Point &rhs)
{
	os << "(" << rhs._ix
	   << "," << rhs._iy
	   << ")";
	return os;
}

#if 1
bool operator<(const Point &lhs, const Point &rhs)
{
	return lhs.distance() < rhs.distance();
}

#endif
bool operator>(const Point &lhs, const Point &rhs)
{
	return lhs.distance() > rhs.distance();
}

void test0(void)
{
	// set之中不能存放关键字相同的严肃， 默认情况下元素会以升序的方式进行排列
	//
	set<int> numbers{1, 8, 7, 2, 3, 2, 3, 8, 4, 9, 5, 8, 6};
	cout << "numbers's size = " << numbers.size() << endl;

	// cout << numbers[0] << endl; // error 不支持下标访问
	//
	set<int>::iterator it = numbers.begin();
	cout << *it << endl;
	// *it = 10; // read-only, 不能修改set中的元素值
	// 底层实现时红黑树 ---> 平衡二叉树 ---> 加快查找元素的速度O(logN)
	
	// set的insert方法，可能失败，例如传入重复值（1），所以返回值类型
	// 是pair。 第一个参数是迭代器， 第二个是bool
	//
	pair<set<int>::iterator, bool> ret = numbers.insert(1);
	//pair<set<int>::iterator, bool> ret = numbers.insert(10);
	if(ret.second)
	{
		cout << "numbers添加元素成功" << endl;
		cout << *(ret.first) << endl;
	}
	else
		cout << "numbers添加元素失败" << endl;
	
	for(auto &number : numbers)
	{
		cout << number << " ";

	}
	cout << endl;

}


void test1()
{

	pair<string, int> record("hello", 88);
	cout << record.first << "--->" << record.second << endl;

}
	

void test2(void)
{
	// set之中不能存放关键字相同的严肃， 默认情况下元素会以升序的方式进行排列
	//
	set<int, std::greater<int>> numbers{1, 8, 7, 2, 3, 2, 3, 8, 4, 9, 5, 8, 6};
	cout << "numbers's size = " << numbers.size() << endl;

	// cout << numbers[0] << endl; // error 不支持下标访问
	//
	set<int>::iterator it = numbers.begin();
	cout << *it << endl;
	// *it = 10; // read-only, 不能修改set中的元素值
	// 底层实现时红黑树 ---> 平衡二叉树 ---> 加快查找元素的速度O(logN)
	
	// set的insert方法，可能失败，例如传入重复值（1），所以返回值类型
	// 是pair。 第一个参数是迭代器， 第二个是bool
	//
	pair<set<int>::iterator, bool> ret = numbers.insert(10);
	//pair<set<int>::iterator, bool> ret = numbers.insert(10);
	if(ret.second)
	{
		cout << "numbers添加元素成功" << endl;
		cout << *(ret.first) << endl;
	}
	else
		cout << "numbers添加元素失败" << endl;
	
	for(auto &number : numbers)
	{
		cout << number << " ";

	}
	cout << endl;

}

void test3()
{

	// 初始化:
	set<Point, std::greater<Point>> points1{
		Point(1,1),
		Point(2,2),
		Point(3,3),
		Point(4,4),
		Point(5,5)
	};

	set<Point> points;
	// insert 返回值 pair
	pair<set<Point>::iterator, bool> ret = points.insert(Point(1,1));
	
	for(auto p : points)
	{
		cout << p << endl;
	}
	
	if(ret.second)
	{
		cout << "insert success!" << endl;
	}
	else
		cout << "insert failed." << endl;
	
	set<Point>::iterator it = points1.begin();
	
	while(it != points1.end())
	{
		cout << *it << endl;
		++it;
	}



}

int main()
{
	test3();
	//test0();
}

