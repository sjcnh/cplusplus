 ///
 /// @file    io1.cc
 /// @author  sjcnh(itechie@163.com)
 /// @date    2018-06-08 15:43:29
 ///

#include <string>
#include <limits>
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::string;


// good bit  有效状态
// badbit    系统级别的故障，无法恢复
// failbit   可以恢复的错误
// eofbit    到达了当前流的末尾

void printCin()
{
	cout << "cin's goodbit = " << cin.good() << endl;
	cout << "cin's badbit = " << cin.bad() << endl;
	cout << "cin's failbit = " << cin.fail() << endl;
	cout << "cin's eofbit = " << cin.eof() << endl;
}

void test()
{
	cout << "sizeof(cout) = " << sizeof(cout) << endl;
	cout << "sizeof(cin) = " << sizeof(cin) << endl;

	printCin();

	int num = 0;
	while(cin) // 判断流的状态是不是有效状态
	{
		cin >> num;
		cout << "num = " << num << endl;
	}

	cout << endl;
	printCin();
	cout << endl;

	cin.clear(); // 重置流的状态
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // 清空缓冲区
	printCin();

}

int main()
{
	test();	
}
