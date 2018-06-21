 ///
 /// @file    priority_queue.cc
 /// @author  LJW
 /// @date    2018-06-21 17:22:49
 ///
 
#include <unistd.h>
#include <queue>
#include <iostream>
#include <cmath>
#include <vector>
using std::cout;
using std::endl;
using std::vector;
using std::priority_queue;

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
	   << ")" << endl;
	return os;
}

void test()
{

	int arr[10] = {3, 1, 4, 8, 6, 9, 5, 2, 7, 0};
	priority_queue<int, vector<int>, std::greater<int>> pqueue;
	for(int idx = 0; idx < 10; ++idx)
	{
		pqueue.push(arr[idx]);	
		cout << "priority_queue 's element : " << pqueue.top() << endl;
	}

	cout << endl << endl;
	while(!pqueue.empty())
	{
		cout << pqueue.top() << " ";
		pqueue.pop();
	}
}

// 自定义函数对象的方式来完成比较  (比较方式）
struct Comparator
{
	bool operator()(const Point &lhs, const Point &rhs)
	{
		return lhs.distance() > rhs.distance();
	}
};

bool operator<(const Point &lhs, const Point &rhs)
{
	return lhs.distance() < rhs.distance();
}

void test1()
{
	// comparator 函数对象  
	priority_queue<Point, vector<Point>, Comparator> pqueue;

//	pqueue.push(Point(1,1));
//	pqueue.push(Point(1,1));
//	pqueue.push(Point(1,1));
//	pqueue.push(Point(1,1));
	cout << endl << endl;
	Point points[5] = {
		Point(1,1),
		Point(2,2),
		Point(3,3),
		Point(4,4),
		Point(5,5)
	};

	priority_queue<Point, vector<Point>, Comparator> pque(points, points + 5);
	
	while(!pque.empty())
	{
		cout << pque.top();
		pque.pop();
	}
}
int main()
{
	test1();
}
