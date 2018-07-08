 ///
 /// @file    1.cc
 /// @author  LJW
 /// @date    2018-07-06 00:17:58
 ///
 
#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
using std::stringstream;
using std::istringstream;
using std::ostringstream;
using std::ifstream;
using std::cout;
using std::endl;
using std::string;

int main()
{
	ifstream ifs("server.conf");
	if(!ifs)
		cout << "open error!" << endl;

	stringstream ss;

	std::string line;
	string key;
	string value;
	while(getline(ifs, line))
	{
		ss << line;
		ss >> key >> value;
		cout << key << value << endl;
	}
	
	while(ss)
	{
		cout << key << "--->" << value << endl;

	}
	

}
