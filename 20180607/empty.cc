 ///
 /// @file    empty.cc
 /// @author  sjcnh(itechie@163.com)
 /// @date    2018-06-07 10:03:15
 ///
#include <string.h>
#include <stdio.h>

#include <iostream>
using std::cout;
using std::endl;

// 空类还是会占据一个字节的大小，是为了区分出对象的不同
class Empty
{
};

int main()
{
	Empty e1;
	Empty e2;

	Empty e3 = e1;
	
	e2 = e1;
	printf("&e1 = %p\n", &e1);
	printf("&e2 = %p\n", &e2);
	cout << "sizeof(Empty) = " << sizeof(Empty) << endl;

}
