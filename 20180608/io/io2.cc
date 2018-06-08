 ///
 /// @file    io2.cc
 /// @author  sjcnh(itechie@163.com)
 /// @date    2018-06-08 15:26:50
 ///
#include <string>
#include <fstream>
#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::fstream;
using std::string;
using std::vector;

void test(void)
{
	ifstream ifs("io2.cc"); // 文件输入流要求文件必须存在
	
	if(!ifs)
	{
		cout << "ifstream open error!" << endl;
		return;
	}
	string line;
	while(getline(ifs, line))
	{
		cout << line << endl;
	}

	ifs.close();
}


int main()
{
	
	test();	
}
