 ///
 /// @file    iniString.cc
 /// @author  LJW
 /// @date    2018-06-28 16:44:01
 ///
 
#include <string>
#include <iostream>
using std::cout;
using std::endl;
using std::string;

class Different
{
public:
	bool checkDifferent(string iniString)
	{
		if(iniString.empty())
			return true;
		
		auto i = iniString.begin();
		auto end = iniString.end();

		for(;i != end; ++i)
		{
			for(auto j = i + 1; j != end; ++j)
			{
				if(*i == *j)
					return false;
			}
		}
		return true;
	}

};

int main()
{
	string s1("hhhhhhhhhhhhhhh");
	string s2("acbdbesy");
	Different d;
	cout <<	d.checkDifferent(s1) << endl;
	cout <<	d.checkDifferent(s2) << endl;
	

}
