 ///
 /// @file    container.cc
 /// @author  LJW
 /// @date    2018-06-20 20:42:01
 ///

#include <vector>
#include <list>
#include <deque>
#include <iostream>
using std::cout;
using std::endl;
using std::vector;
using std::deque;
using std::list;

#if 0
template <typename Container>
void display(const Container &c)
{
	typename Container::const_iterator cit = c.begin();
	for( ; cit != c.end(); ++cit)
	{
		cout << *cit << " ";
	}
	cout << endl;	
}
#endif

template <typename Container>
void display(const Container &c)
{
	//typename Container::const_iterator cit = c.begin();
	for(auto cit : c)
	{
		cout << cit << " ";
	}
	cout << endl;	
}

void test()
{
	int arr[5] = {1, 2, 1, 2, 1};
	vector<int> vec{1, 2, 3, 4, 5};
	vector<int> vec1(10, 1);
	vector<int> vec2(arr, arr + 5);
	vector<int> vec3; // 空

	cout << vec.at(3) << endl;
	cout << vec.front() << vec.back() << endl;

	display(vec);
	display(vec1);
	display(vec2);
	display(vec3);
}

int main()
{

	test();
}
