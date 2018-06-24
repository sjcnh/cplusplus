 ///
 /// @file    Vector.cc
 /// @author  LJW
 /// @date    2018-06-20 11:10:47
 ///
 

#include <memory>
#include <iostream>
using std::cout;
using std::endl;
using std::allocator;

template <typename T> 
class Vector
{
public:
	typedef T * iterator;
	typedef const T * const_iterator;

	Vector()
	: _start(0)
	, _finish(0)
	, _end_of_storage(0)
	{};

	~Vector()
	{
		// 销毁对象 
		while(_start != _finish)
			_alloc.destroy(--_finish);

		// 回收开辟空间
		if(_start)
			_alloc.deallocate(_start, capacity());
	}

	
	iterator begin()
	{
		return _start;
	}

	iterator end()
	{
		return _finish;
	}

	void push_back(const T &t);
	void pop_back();

	size_t size() const
	{
		return _finish - _start;
	}

	size_t capacity() const
	{
		return _end_of_storage - _start;
	}

private:
	void reallocate(); // 重新分配内存，动态扩容使用
private:
	static std::allocator<T> _alloc;
	T *_start;
	T *_finish;
	T *_end_of_storage;    //
};

template <typename T>
allocator<T> Vector<T>::_alloc; //静态全局变量的初始化


template <typename T>
void Vector<T>::push_back(const T &t)
{	
	if(size() == capacity())
		reallocate();// 动态扩容
	
	// 4. 在新开辟的空间上添加新的元素
	// 构造对象， 在_finish后面继续push_back
	_alloc.construct(_finish++, t);
}

template <typename T>
void Vector<T>::pop_back()
{
	if(_start != _finish) // 非空销毁对象
		_alloc.destroy(--_finish);
}

template <typename T>
void Vector<T>::reallocate()
{

	// 1. 扩容操作
	size_t oldCapacity = capacity();
	// 如果old=0， 那么扩容为1，其他情况2倍
	size_t newCapacity = oldCapacity ? 2 * oldCapacity : 1;

	// 2. 申请空间
	T *tmp = _alloc.allocate(newCapacity); //申请原始的内存

	// 3. 非空， 复制原来数据
	if(_start)
	{
		// memcpy(); // 内置类型的数据
		// copy();  // 调用对象的赋值运算符函数， 意味着对象存在
		std::uninitialized_copy(_start, _finish, tmp); // 复制原来空间的数据
	
		// 回收原来空间的数据
		while(_start != _finish)
			_alloc.destroy(--_finish);

		// 回收原来空间
		_alloc.deallocate(_start, oldCapacity);
	}

	_start = tmp;
	_finish = _start + oldCapacity;
	_end_of_storage = _start + newCapacity;
}

class Point
{
public:
	Point(int ix = 0, int iy = 0)
	: _ix(ix)
	, _iy(iy)
	{	cout << "Point(int, int)" << endl;	}

	~Point()
	{	cout << "~Point()" << endl;	}

	Point(const Point &rhs)
	: _ix(rhs._ix)
	, _iy(rhs._iy)
	{
		cout << "Point(const Point &)" << endl;
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
	   << ")" ;
	return os;
}

template <typename Container>
void display(Container &c)
{
	cout << "c's size = " << c.size() << endl
		 << "c's capacity = " << c.capacity() << endl << endl;
}
	
int main()
{
	Vector<Point> points;
	display(points);

	points.push_back(Point(1, 1));
	display(points);

	points.push_back(Point(3, 3));
	display(points);

	points.push_back(Point(5, 5));
	display(points);

	Vector<Point>::iterator it = points.begin();
	while(it != points.end())
	{
		cout << *it << endl;
		++it;
	}

	return 0;
}
