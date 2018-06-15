 ///
 /// @file    Stack.cc
 /// @author  LJW
 /// @date    2018-06-08 21:47:43
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Stack
{
public:
	Stack()
	: _top(-1)
	{

	}

	void push(int num)
	{
		if(!this->full())
		{
			++_top;
			_arr[_top] = num;
		}
		else
		{
			cout << "Full of stack!" << endl;
			return ;
		}
	}

	void pop()
	{
		if(!this->empty())
		{ 
			--_top;
		}
		else
		{
			cout << "Stack is empty!" << endl;
			return ;
		}

	}

	int top()
	{
		if(this->empty())
		{
			return -1;
		}
		else
		{
			cout << "top=" << _top  << " element:" << _arr[_top] << endl;
			return _top;
		}
	}

	bool empty()
	{
		if(-1 == _top) return true;
		return false;
	}

	bool full()
	{
		if(10 == _top) return true;
		return false;
	}

private:
	int _arr[10];	
	int _top;
};

//int Stack::_top = -1;// top指针

int main()
{
	Stack s; // 创建stack
	s.push(10);
	s.push(12);
	s.push(14);
	s.top();
	s.pop();
	s.top();
	s.pop();
	s.top();
	s.pop();
	s.top();
	s.pop();
	s.top();

	return 0;

}
