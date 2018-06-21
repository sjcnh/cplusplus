 ///
 /// @file    reverse_iterator.cc
 /// @author  LJW
 /// @date    2018-06-21 22:28:58
 ///
 
#include <set>
#include <algorithm>
#include <list>
#include <iterator>
#include <vector>
#include <iostream>
using std::cout;
using std::endl;
using std::vector;
using std::back_insert_iterator;
using std::list;
using std::copy;
using std::set;


void test()
{
	vector<int> nums{1, 2, 3, 4, 5};
	vector<int>::reverse_iterator rit = nums.rbegin();
	while(rit != nums.rend())
	{
		cout << *rit << " ";
		++rit;
	}
	cout << endl;

}

void test1()
{
	vector<int> numbers{1, 2, 3};
	list<int> liNum;

	// std::back_insert_iterator内部使用了push_back添加元素，只能操作vector，deque，list这三种容器
	copy(numbers.begin(), numbers.end(), std::back_insert_iterator<list<int>>(liNum));
	copy(liNum.begin(), liNum.end(), std::ostream_iterator<int>(cout, " "));
	cout << endl; 
	
	// std::front_insert_iterator内部使用了push_front添加元素，只能操作deque，list, forward_list这三种容器
	copy(numbers.begin(), numbers.end(), std::front_insert_iterator<list<int>>(liNum));
	copy(liNum.begin(), liNum.end(), std::ostream_iterator<int>(cout, " "));
	cout << endl;


	auto lit = liNum.begin();
	++lit;
	
	// insert_iterator 内部使用的是insert方法， 操作的容器很多
	set<int> setNums;
	auto sit = setNums.begin();
	copy(numbers.begin(), numbers.end(), std::insert_iterator<set<int>>(setNums, sit));
	copy(setNums.begin(), setNums.end(), std::ostream_iterator<int>(cout, " "));
	cout << endl; 
	
}


int main()
{
	test1();

}
