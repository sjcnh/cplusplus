 ///
 /// @file    remove.cc
 /// @author  LJW
 /// @date    2018-06-23 18:09:11
 ///
 
#include <algorithm>
#include <iostream>
#include <vector>
#include <iterator>

using std::cout;
using std::remove;
using std::endl;
using std::vector;


void test()
{
	vector<int> numbers{1, 2, 4, 77, 77, 5, 77, 9, 11};

	//1, 2, 4, 5, 77, 9, 11 并没有删除值，而是返回需要删除的第一个元素的地址
	// remove会改变原来容器内容, 如果不注释这条，结果会不同:
//	auto it = remove(numbers.begin(), numbers.end(), 77);

	// 结合erase函数进行操作
//	numbers.erase(it, numbers.end());	
//	std::copy(numbers.begin(), numbers.end(), std::ostream_iterator<int>(cout, " "));

	// erase-remove惯用法
	numbers.erase(remove(numbers.begin(), numbers.end(), 77), numbers.end());
	cout << endl;
	std::copy(numbers.begin(), numbers.end(), std::ostream_iterator<int>(cout, " "));

}

void test1()
{
	vector<int> num;
	num.push_back(1);
	bool flag = true;
	for(auto it = num.begin(); it != num.end(); ++it)
	{
		cout << "num's size = " << num.size() << endl
			 << "num's capacity = " << num.capacity() << endl;
		if(flag)
		{
			num.push_back(2);
			it = num.begin();
			flag = false;
		}
		cout << *it << " " << endl;
	}
	cout << endl;

}


int main()
{

	test1();
	//test();
}
