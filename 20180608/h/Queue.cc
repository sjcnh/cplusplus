 ///
 /// @file    Queue.cc
 /// @author  sjcnh(itechie@163.com)
 /// @date    2018-06-08 22:29:56
 ///
 
#include <iostream>
using std::cout;
using std::endl;


const int kMax = 10;

class Queue
{
public:
	Queue()
	: _front(0)
	, _back(0)
	{

	}

	void push(int num) // 入队
	{
		if(this->full())
		{
			cout << " Queue is full!" << endl;
			return ;
		}
		else
		{
			_data[_back] = num;
			++_back;
		}
	}

	void pop()
	{
		if(this->empty())
		{
			cout << "Queue is empty!" << endl;
			return ;
		}
		else
		{
			for(int idx = _front; idx < _back; ++idx)
			{
				_data[idx] = _data[idx + 1];
			}
			--_back;
		}
	}

	int front()
	{
		cout << _data[_front] << endl;
		return _data[_front];

	}

	int back()
	{
		cout << _data[_back] << endl;
		return _data[_back];
	}

	bool empty()
	{
		if(_front == _back)
			return true;
		else
			return false;
	}

	bool full()
	{
		if((*this)._back == kMax - 1)
			return true;
		else
			return false;
	}

private:
	int _data[kMax];
	int _front;
	int _back;

};


int main()
{
	Queue q;
	q.push(1);
	q.front();
	q.back();
	q.push(2);
	q.front();
	q.back();

	return 0;

}
