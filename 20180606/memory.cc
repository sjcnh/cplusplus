 ///
 /// @file    memory.cc
 /// @author  sjcnh(itechie@163.com)
 /// @date    2018-06-06 14:33:18
 ///

#include <string.h>
#include <stdio.h>
#include <iostream>
using std::cout;
using std::endl;

int a = 0; // 全局/静态区
int * p1;
static int d = 1;
const int e = 10; // 文字常量区

int test()
{
	int b;
	char s[] = "12345";
	const int f = 100; // 栈区，跟生命周期有关
	char *p2;
	const char *p3 = "12345";
	static int c = 0; // 局部静态
	
	
	printf("&a = %p\n", &a);
	printf("&b = %p\n", &b);
	printf("&s = %p\n", s);
	printf("&p1 = %p\n", &p1);
	printf("&f = %p\n", &f);
	printf("&p2 = %p\n", &p2);
	printf("&c = %p\n",&c);
	printf("&p3 = %p\n", &p3);

	return 0;
}
int main()
{
	test();
	return 0;
}
