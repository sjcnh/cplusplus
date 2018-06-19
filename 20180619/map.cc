 ///
 /// @file    map.cc
 /// @author  LJW
 /// @date    2018-06-19 22:51:02
 ///

#include <string>
#include <iostream>
#include <map>
using std::cout;
using std::endl;
using std::string;
using std::map;
using std::cin;

int main()
{
	map<string, size_t> word_count;
	string word;
	while(cin >> word)
		++word_count[word];
	for(const auto &w : word_count)
	{		
		cout << w.first << " occurs " << w.second 
			 << ((w.second > 1) ? " times" : " time") << endl;
	}
	
	

}
