 ///
 /// @file    sequenceContainer.cc
 /// @author  LJW
 /// @date    2018-06-15 10:38:22
 ///
 
#include <iostream>
#include <vector>
#include <deque>
#include <list>
using std::cout;
using std::endl;
using std::vector;
using std::list;
using std::deque;  

template <typename Container>
void display(const Container & c)
{
	typename Container::const_iterator cit = c.begin();
	for( ; cit != c.end(); ++cit)
	{
		cout << *cit << " ";
	}
	cout << endl;
}
	
int main()
{
	int arr[5] = {1, 2, 3, 4, 5};
	// vector的使用
	// 初始化方式
	cout << "vector的使用" << endl;
	vector<int> numbers1{1, 2, 3, 4, 5};
	vector<int> numbers(10, 1);
	// first, last
	vector<int> numbers2(arr, arr + 5);
	vector<int>::const_iterator cit = numbers2.begin();
	display(numbers);
	cout << endl;

	cout << "sizeof(vector) = " << sizeof(numbers) << endl;
	cout << "vector's size = " << numbers.size() << endl;
	cout << "vecotr's capacity = " << numbers.capacity() << endl;

	numbers.push_back(0);
	display(numbers);
	cout << "vector's size = " << numbers.size() << endl;
	cout << "vecotr's capacity = " << numbers.capacity() << endl;

	numbers.shrink_to_fit();
	cout << "vector's size = " << numbers.size() << endl;
	cout << "vecotr's capacity = " << numbers.capacity() << endl;
	numbers.clear();
	numbers.shrink_to_fit();
	cout << "vector's size = " << numbers.size() << endl;
	cout << "vecotr's capacity = " << numbers.capacity() << endl;

	// list的使用
	// list<int> li(10, 1)		
	cout << "list的使用" << endl;
	list<int> li(arr, arr + 5);
	//list<int> li(10);
	cout << "list's size = " << li.size() << endl;
	// list 没有capacity()方法
	//auto lit = li.begin(); //  auto可以进行自动推断
//		while(lit != li.end())
//		{
//			cout << *lit << " ";
//			++lit;
//		}
	display(li);
	// list<int>::const_iterator lit = li.begin();
	auto lit = li.begin();
	cout << "*lit = " << *lit << endl;
	li.insert(lit, 33);
	cout << "*lit = " << *lit << endl;
	display(li);
	lit = li.insert(lit, 99);
	cout << "*lit = " << *lit << endl;
	display(li);
	li.insert(lit, 1000);
	display(li);
	// deque的使用
	//
	cout << "deque的使用" << endl;
	deque<int> deq(arr, arr + 5);
	cout << " dequeue[3] = " << deq[3] << endl;
	// deque 没有 capacity
	// cout << "dequeue's capacity" << deq.capacity() << endl;
	display(deq);

}
