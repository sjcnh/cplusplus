 ///
 /// @file    cQueue.cc
 /// @author  LJW
 /// @date    2018-07-03 22:30:10
 ///
 
#include <iostream>
#include <stack>
using std::cout;
using std::endl;
using std::stack;

template <typename T>
class cQueue
{
public:
	cQueue();
	~cQueue();
	
	void appendTail(const T &node);
	T deleteHead();

private:
	stack<T> stack1;
	stack<T> stack2;
};

// 类外实现时，加T的有类名::   返回值    形参
// 但是，构造函数不需要
template <typename T>
cQueue<T>::cQueue()
{
	cout << "cQueue()" << endl;
}

template <typename T>
void cQueue<T>::appendTail(const T &node)
{
	stack1.push(node);
}

template <typename T>
T cQueue<T>::deleteHead()
{
	if(stack2.empty())
	{
		while(stack1.size())
		{
			// 定义一个引用，省去拷贝的开销!
			T &data = stack1.top();
			stack1.pop();
			stack2.push(data);
		}
	}
	T ret;
	if(stack2.empty())
	{
		cout << "queue is empty!!" << endl;
		return ret;
	}
	ret = stack2.top();
	stack2.pop();
	return ret;
}

int main()
{
	cQueue<int> *q = new cQueue<int>();
	q->appendTail(5);
	q->appendTail(6);
	q->appendTail(8);
	cout << q->deleteHead() << endl;
	q->appendTail(11);

	cout << q->deleteHead() << endl;
	return 0;
}
