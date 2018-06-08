 ///
 /// @file    vector.cc
 /// @author  sjcnh(itechie@163.com)
 /// @date    2018-06-08 16:02:00
 ///

#include <vector>
#include <iostream>
using std::cout;
using std::cin;
using std::vector; // 动态数组
using std::endl;

// 动态数组vector  可以自动进行扩容，但是是有开销的，是有成本的
// 实现的具体步骤
// 1.当size == capacity，并且需要添加新元素时，进行扩容操作:
//		1）先申请2 * capacity的空间
//		2）然后把原来空间的元素copy到新申请的空间
//		3）再添加新的元素
//		4）最后释放原来开辟的空间
//
//
//
//
//
int arr[1]; // 空间不能扩展

void displayCapacity(vector<int> & vec)
{
	cout << "vector's size = " << vec.size() << endl;
	cout << "vector's capacity = " << vec.capacity() << endl;
}


void test()
{
	vector<int> numbers;
	//numbers.reserve(100); // 预先申请空间

	displayCapacity(numbers);
	numbers.push_back(1); 
	displayCapacity(numbers);
	numbers.push_back(1); 
	displayCapacity(numbers);
	numbers.push_back(1); 

	for(int idx = 0; idx != numbers.size(); ++idx)
	{
		coud << numbers[idx] << " ";
	}

}

int main()
{
	test();
}
