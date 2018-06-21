 ///
 /// @file    ostream_iterator.cc
 /// @author  LJW
 /// @date    2018-06-21 21:01:17
 ///
 
#include <iterator>
#include <vector>
#include <iostream>
#include <algorithm>
using std::cout;
using std::endl;
using std::vector;
using std::ostream_iterator;

int main()
{
	// num是随机迭代器，所以包含输入迭代器的功能
	vector<int> num{1, 2, 3, 4, 5};
	// 迭代器适配器，设计模式就是适配器模式
	ostream_iterator<int> osi(cout, " ");//  构造函数  第二参数 分隔符
	std::copy(num.begin(), num.end(), osi);
	cout << endl;

		
}
