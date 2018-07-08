 ///
 /// @file    iotest.cc
 /// @author  LJW
 /// @date    2018-07-05 23:21:16
 ///
 
#include <string>
#include <iostream>
#include <fstream>
using std::ifstream;
using std::string;
using std::cout;
using std::endl;

int main()
{
	ifstream ifs("io1.cc");
	if(!ifs)
		cout << "ifstream is open failed!" << endl;

	string line;
	while(getline(ifs, line))
	{
		cout << line << endl;

	}

}
