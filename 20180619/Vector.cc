 ///
 /// @file    Vector.cc
 /// @author  LJW
 /// @date    2018-06-24 10:30:44
 ///
 
#include <memory>
#include <iostream>
using std::cout;
using std::endl;
using std::allocator;

template<typename T>
class Vector
{
public:
	typedef T *iterator;
	typedef const T *const_iterator;
	Vector()
	: _start(0)
	, _finish(0)
	, _end_of_storage(0)
	{}
	
	~Vector();

	iterator begin(){	return _start;	}
	iterator end(){	return _finish;	}

	void push_back(const T &t);

	void pop_back();

	size_t size() const
	{	return _finish - _start;	}

	size_t capacity() const
	{	return _end_of_storage - _start;	}



private:
	void reallocate();
private:
	static allocator<T> _alloc;

	T *_start;
	T *_finish;
	T *_end_of_storage;
};

template <typename T>
allocator<T> Vector<T>::_alloc;

template <typename T>
Vector<T>::~Vector()
{
	// 销毁对象
	while(_start != _finish)
		_alloc.destroy(--_finish);
	// 回收开辟的空间
	if(_start)
		_alloc.deallocate(_start, capacity());
}

template <typename T>
void Vector<T>::reallocate()
{
	size_t oldCapacity = capacity();
	size_t newCapacity = oldCapacity ? 2 * oldCapacity : 1;

	T *tmp = _alloc.allocate(newCapacity);
	if(_start)
	{
		std::uninitialized_copy(_start, _finish, tmp);

		while(_start != _finish)
			_alloc.destroy(--_finish);

		_alloc.deallocate(_start, oldCapacity);  
	}
	_start = tmp;
	_finish = _start + oldCapacity;
	_end_of_storage = _start + newCapacity;

}

template <typename T>
void Vector<T>::push_back(const T &t)
{
	if(size() == capacity())
		reallocate();

	// construct object
	_alloc.construct(_finish++, t);
	
}

template <typename T>
void Vector<T>::pop_back()
{
	if(_start != _finish)
		_alloc.destroy(--_finish);
}

class Point
{
public:
	Point(int ix = 0, int iy = 0)
	: _ix(ix)
	, _iy(iy)
	{
		cout << "Point(int, int)" << endl;
	}

	Point(const Point &rhs)
	: _ix(rhs._ix)
	, _iy(rhs._iy)
	{
		cout << "Point(const Point &)" << endl;
	}

	~Point()
	{
		cout << "~Point()" << endl;
	}

	friend std::ostream &operator<<(std::ostream &os, const Point &rhs);

	

private:
	int _ix;
	int _iy;

};

std::ostream &operator <<(std::ostream &os, const Point &rhs)
{
	os << "(" << rhs._ix
	   << "," << rhs._iy
	   << ")" ; // no format control
	return os;
}

template <typename Container>
void display(Container & c)
{
	cout << "size = " << c.size() << endl;
	cout << "capacity = " << c.capacity() << endl << endl;
}

int main()
{
	Vector<Point> points;

	points.push_back(Point(1, 1));
	display(points);
	points.push_back(Point(2, 2));
	display(points);
	points.push_back(Point(3, 3));
	display(points);
	cout << endl;

	Vector<Point>::iterator it = points.begin();
	while(it != points.end())
	{
		cout << *it << endl;
		++it;
	}
	cout << endl;

	return 0;
}
