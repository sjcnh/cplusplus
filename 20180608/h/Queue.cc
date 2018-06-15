 ///
 /// @file    Queue.cc
 /// @author	LJW 
 /// @date    2018-06-08 22:29:56
 ///
 
#include <iostream>
using std::cout;
using std::endl;


const int kMax = 5;

class Queue
{
public:
	Queue()
	: _front(0)
	, _back(-1)
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
			++_back;
			_data[_back] = num;
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
			for(int idx = _front; idx != _back; ++idx)
			{
				_data[idx] = 0;
				_data[idx] = _data[idx + 1];
			}
			--_back;
		}
		if(this->empty())
		{
			_data[_front] = 0;
		}
		cout << "pop()" << _back << endl;
	}

	int front()
	{
		cout << "front()" << _data[_front] << endl;
		return _data[_front];

	}

	int back()
	{
		cout << "back()" << _data[_back] << endl;
		return _data[_back];
	}

	bool empty()
	{
		if(_front == (_back + 1))
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
	int _data[kMax] = {0};
	int _front;
	int _back;

};


int main()
{	
	Queue q;
	q.pop();
	cout << q.empty() << endl;
	
	q.push(999);
	q.front();
	q.back();
	q.push(888);
	q.front();
	q.back();
	q.push(777);
	q.front();
	q.back();
	q.push(666);
	q.front();
	q.back();
	q.push(555);
	q.front();
	q.back();
	q.push(444);
	q.front();
	q.back();
	q.pop();
	q.front();
	q.back();
	q.pop();
	q.front();
	q.back();
	q.pop();
	q.front();
	q.back();
	q.pop();
	q.front();
	q.back();
	q.pop();
	q.front();
	q.back();

	return 0;

}
