 ///
 /// @file    for_each.cc
 /// @author  LJW
 /// @date    2018-06-23 17:20:18
 ///
 
#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
using std::cout;
using std::string;
using std::endl;
using std::vector;

void display(int num) // int &num
{
	++num;
	cout << num << " ";
}

void test()
{
	vector<int> nums{1, 2, 3, 4, 5, 6};
//	for_each(nums.begin(), nums.end(), display); // 函数对象

	// lambda表达式  匿名函数对象方式
	for_each(nums.begin(), nums.end(), [](int num){
		++num;	
		cout << num << " ";
	}); // 函数对象
	cout << endl;
	for(auto &num : nums)
	{

		cout << num << " ";
	}
	cout << endl;

	// find element = 4
	auto it = std::find(nums.begin(), nums.end(), 4);
	cout << "it = " << *it << endl;
	// find element = 7  时间复杂度O(n)
	auto it1 = std::find(nums.begin(), nums.end(), 7);
	cout << "it1 = " << *it1 << endl;
}


void test1()
{
	string s1 = "why waste time learning, when ignorance is instantaneous?";
	string s2 = "ignorance";

	auto it = std::search(s1.begin(), s1.end(), s2.begin(), s2.end());

	while(it != s1.end())
	{
		cout << *it;
		++it;
	}
	cout << endl;

}

void test2()
{
	vector<int> vec1{1, 2, 3, 4, 5};
	vector<int> vec2{2, 3};

	auto it = std::search(vec1.begin(), vec1.end(), vec2.begin(), vec2.end());
	while(it != vec1.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
}

int main()
{
	test2();

}
