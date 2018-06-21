 ///
 /// @file    istream_iterator.cc
 /// @author  LJW
 /// @date    2018-06-21 21:59:51
 ///
 
#include <vector>
#include <iterator>
#include <iostream>
#include <algorithm>
using std::copy;
using std::cout;
using std::endl;
using std::vector;
using std::istream_iterator;
using std::ostream_iterator;



int main()
{
	vector<int> numbers;
	istream_iterator<int> isi(std::cin);
	// isi 起始  匿名对象 end  copy到numbers的begin
	copy(isi, istream_iterator<int>(), std::back_inserter(numbers)); // numbers.begin这样是没有空间和元素的，所以会发生段错误！需要使用插入迭代器
	
	
	ostream_iterator<int> osi(std::cout, " ");
	copy(numbers.begin(), numbers.end(), osi);

}
