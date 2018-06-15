 ///
 /// @file    Queue.cc
 /// @author  LJW
 /// @date    2018-06-14 20:58:48
 ///
 
#include <iostream>
using std::cout;
using std::endl;

template <typename T, int kSize = 10>
class Queue
{
public:
	Queue();
	~Queue();
	bool empty() const;
	bool full() const;
	void push(int num);
	void pop();
	T front();
	T back();

private:
	int _size;
	int _front;
	int _rear;
	T *_base;
};
template <typename T, int kSize>
Queue<T, kSize>::Queue()
: _size(kSize)
, _front(0)
, _rear(0)
, _base(new int[_size]())
{
	cout << "Queue()" << endl;
}

template <typename T, int kSize>
Queue<T, kSize>::~Queue()
{
	delete []_base;
}

template <typename T, int kSize>
bool Queue<T, kSize>::empty() const
{
	return _front == _rear;
}

template <typename T, int kSize>
bool Queue<T, kSize>::full() const
{
	return _front == (_rear + 1) % _size;
}

template <typename T, int kSize>
void Queue<T, kSize>::push(int num)
{
	if(!full())
	{
		_base[_rear++] = num;
		_rear %= _size;
	}
	else
		cout << " Queue is full!" << endl;

}

template <typename T, int kSize>
void Queue<T, kSize>::pop()
{
	if(!empty())
	{
		++_front;
		_front %= _size;
	}
	else
		cout << "queue is empty" << endl;
}

template <typename T, int kSize>
T Queue<T, kSize>::front()
{
	return _base[_front];
}

template <typename T, int kSize>
T Queue<T, kSize>::back()
{
	return _base[(_rear - 1 + _size) % _size];
}

int test()
{
	

	return 0;
}

int main()
{

}
