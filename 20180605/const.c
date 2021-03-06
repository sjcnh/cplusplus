 ///
 /// @file    const.c
 /// @author  sjcnh(itechie@163.com)
 /// @date    2018-06-05 15:36:44
 ///
 
#include <iostream>
using std::cout;
using std::endl;

#define kMax 100

int test0()
{
	int num = 10;
	cout << num * kMax << endl;
	return 0;
}

int test1()
{
	int a = 10;
	int b = 22;
	const int *pa = &a; // 常量指针(pointer to const)
	//*pa = 11;
	pa = &b;

	int const *pb = &a; // 同上
	//*pb = 11;
	pb = &b;

	int * const pc = &a; // 指针常量（const pointer）
	*pc = 11;
//	pc = &b;
	return 0;
}
int main()
{
	test0();
	return 0;
}
