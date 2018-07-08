 ///
 /// @file    CStack.cc
 /// @author  LJW
 /// @date    2018-07-05 16:02:29
 ///
 
#include <iostream>
#include <queue>
using std::queue;
using std::cout;
using std::endl;

template <typename T>
class CStack
{
public:
	CStack();
	~CStack();

	void push(const T &t);
	T pop();
	T top();

private:
	queue<T> queue1;
	queue<T> queue2;

};

template <typename T>
CStack<T>::CStack()
{
	cout << "CStack()" << endl;
}

template <typename T>
CStack<T>::~CStack()
{
	cout << "~CStack()" << endl;
}

template <typename T>
void CStack<T>::push(const T &element)
{
	if(queue1.empty() && queue2.empty())
		queue1.push(element);
	else // insure the element will be pushed into the empty queue
		if(!queue1.empty())
			queue1.push(element);
		else
			queue2.push(element);
}

template <typename T>
T CStack<T>::pop()
{
	T t;
	if(queue1.empty() && queue2.empty())
	{
		cout << "stack is empty!" << endl;
		return t;
	}
	else
	{
		// queue1 is empty
		if(queue1.empty())
		{
			// push element from queue2, and the last one will be the target.
			while(queue2.size() != 1)
			{
				queue1.push(queue2.front());
				queue2.pop();
			}
			t = queue2.front(); // last element first out
			queue2.pop();
		}
		else // queue2 is empty
		{
			while(queue1.size() != 1)
			{
				queue2.push(queue1.front());
				queue1.pop();
			}
			t = queue1.front();
			queue1.pop();
		}
		return t;
	}
}

template <typename T>
T CStack<T>::top()
{
	T t;
	if(queue1.empty() && queue2.empty())
		return t;
	else
	{
		if(!queue1.empty())
			t = queue1.back();
		else
			t = queue2.back();
	}
}


int main()
{
	CStack<int> cstack;
	cstack.push(1);
	cstack.push(2);
	cstack.push(3);
	cstack.push(4);
	cstack.push(5);
	cout << "the top element is " << cstack.top() << endl;
	cout << " pop " << cstack.pop() << endl;
	cout << "the top element is " << cstack.top() << endl;

}
