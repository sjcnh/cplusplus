 ///
 /// @file    replace.cc
 /// @author  LJW
 /// @date    2018-06-23 21:51:22
 ///
 
#include <algorithm>
#include <iostream>
#include <vector>
#include <iterator>
using std::ostream_iterator;
using std::vector;
using std::cout;
using std::endl;
using std::replace_if;

void test()
{
	vector<int> vec{1, 2, 5, 7, 9};

	std::less<int> lt; // lt(x1, x2);
	// std::bind1st, std::bind2nd 函数适配器（绑定器）
	replace_if(vec.begin(), vec.end(), std::bind2nd(lt, 4), 10);

	//
	std::copy(vec.begin(), vec.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

}

int main()
{

	test();
}
