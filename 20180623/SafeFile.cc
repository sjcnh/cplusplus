 ///
 /// @file    SafeFile.cc
 /// @author  LJW
 /// @date    2018-06-26 23:14:44
 ///
 
#include <stdio.h>
#include <string>
#include <iostream>
using std::cout;
using std::endl;
using std::string;

// 资源管理技术 ： RAII(Resource Acquisition Is Initialization)
//
class SafeFile
{
public:
	SafeFile(FILE * fp)
	: _fp(fp)
	{
		cout << "SafeFile()" << endl;
		if(_fp == NULL)
		{
			cout << "file not exist!" << endl;
			return;
		}	
	}

	void write(const string &msg)
	{
		fwrite(msg.c_str(), 1, msg.size(), _fp);
	}

	string read(const string &msg)
	{
		return fread(msg.c_str(), 1, msg.size(), _fp);
	}

	~SafeFile()
	{
		if(_fp)
		{
			fclose(_fp);
			cout << ">> fclose(_fp)" << endl;
		}
	}

private:
	FILE * _fp;

};

int main()
{
	SafeFile sf(fopen("test.txt", "w+"));
	sf.write("hello, world");

	return 0;

}
