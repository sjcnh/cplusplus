 ///
 /// @file    te.cc
 /// @author  LJW
 /// @date    2018-07-05 23:29:36
 ///
 
#include <iostream>
#include <string>
#include <fstream>
using std::ifstream;
using std::string;
using std::cout;
using std::endl;

int main()
{
	ifstream ifs("iotest.cc");
	if(!ifs)
		cout << "error " << endl;
	string line;
	while(getline(ifs, line))
	{
		cout << line << endl;
	}


	return 0;
}
