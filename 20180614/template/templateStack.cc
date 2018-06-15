 ///
 /// @file    templateStack.cc
 /// @author  LJW
 /// @date    2018-06-14 20:36:08
 ///

#include <string>
#include <iostream>
using std::cout;
using std::endl;
using std::string;

template <typename T, int kSize = 10>
class Stack
{
public:
	Stack();
	~Stack();
	bool full() const;
	bool empty() const;
	void push(const T &t);
	void pop();
	T top();

private:
	int _top;
	T *_arr;
};


template <typename T, int kSize>
Stack<T, kSize>::Stack()
: _top(-1)
, _arr(new T[kSize]())
{
	cout << "Stack()" << endl;
}

template <typename T, int kSize>
Stack<T, kSize>::~Stack()
{
	delete []_arr;
}

template <typename T, int kSize>
bool Stack<T, kSize>::full() const
{
	return _top == (kSize - 1);
}

template <typename T, int kSize>
bool Stack<T, kSize>::empty() const
{
	return _top == -1;
}

template <typename T, int kSize>
void Stack<T, kSize>::push(const T &t)
{
	if(!full())
	{
		_arr[++_top] = t;
	}
	else
		cout << "Stack is full, can't push any element" << endl;
}

template <typename T, int kSize>
void Stack<T, kSize>::pop()
{
	if(!empty())
	{
		--_top;
	}
	else 
		cout << "Stack is empty, can't pop!" << endl;
}

template <typename T, int kSize>
T Stack<T, kSize>::top()
{
	return _arr[_top];
}

int test()
{
	Stack<int> stack;
	cout << "is stack empty?" << stack.empty() << endl;
	stack.push(1);
	cout << "is stack empty?" << stack.empty() << endl;

	for(int idx = 2; idx < 12; ++idx)
	{
		stack.push(idx);
	}
	cout << "is stack full" << stack.full() << endl;

	while(!stack.empty())
	//for(int idx = 0; idx != 10; ++idx)
	{
		cout << stack.top() << " ";
		stack.pop();
	}
	cout << endl;
	return 0;

}
int main()
{
	test();
}
