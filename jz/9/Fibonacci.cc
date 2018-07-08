 ///
 /// @file    Fibonacci.cc
 /// @author  LJW
 /// @date    2018-07-07 16:32:06
 ///
 
#include <iostream>
#include <time.h>
using std::cout;
using std::endl;

int Fibonacci(int n)
{
	if(n == 0)
		return 0;
	if(n == 1)
		return 1;
	return Fibonacci(n - 1) + Fibonacci(n - 2);
}

int Fibonacci2(int n)
{
	int arr[2] = {0, 1};
	if(n <= 1)
		return arr[n];
	int f1 = 1;
	int f2 = 0;
	int f = 0;
		
	for(int i = 2; i <= n; ++ i)
	{
		f = f1 + f2;
		f2 = f1;
		f1 = f;
	}
	return f;
}

void test()
{
	clock_t start_time, end_time;

	start_time = clock();
	cout << Fibonacci(40) << endl;
	end_time = clock();
	cout << "total time is: " << (end_time - start_time) / CLOCKS_PER_SEC << endl; 

	start_time = clock();
	cout << Fibonacci2(40) << endl;
	end_time = clock();
	cout << "total time is: " << (end_time - start_time) / CLOCKS_PER_SEC << endl; 

}

int main()
{
	test();
}
