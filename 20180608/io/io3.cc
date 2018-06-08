 ///
 /// @file    io3.cc
 /// @author  sjcnh(itechie@163.com)
 /// @date    2018-06-08 17:20:59
 ///
 
#include <sstream>
#include <iostream>
#include <string>
#include <fstream>

using std::fstream;
using std::string;
using std::cout;
using std::endl;
using std::istringstream;
using std::ostringstream;
using std::stringstream;
using std::ifstream;

void test()
{
	int num1 = 10;
	int num2 = 20;

	// 把非字符串数据转换成字符串
	// sscanf
	// sprintf
	stringstream ss;
	ss << "number1= " << num1 << " number2= " << num2; // 空格问题 number = 1
	cout << ss.str() << endl;

	// 把缓冲区数据放到word value中
	string word;
	int value;

	// 当确定格式的时候，就可以使用输入流方式完成数据的输入
	// 解析配置文件
	while(ss >> word >> value)
	{	
		cout << word << " " << value << endl;
	}

}

string int2str(int num)
{
	ostringstream oss;
	oss << num;
	return oss.str();
}

void readConfiguration()
{
	ifstream ifs;
	ifs.open("server.conf");
	if(!ifs)
	{
		cout << "ifstream open error!" << endl;
		return ;
	}

	string line;
	string key;
	string value;

	while(getline(ifs, line))
	{
		istringstream iss(line);
		iss >> key >> value;
		cout << key << " ---> " << value << endl;
	}
	ifs.close();
}


int main()
{
	test();
	int num = 123;
	cout << "int2str" << int2str(num) << endl;
	
	readConfiguration();
	return 0;
}
