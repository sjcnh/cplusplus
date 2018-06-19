 ///
 /// @file    map1.cc
 /// @author  LJW
 /// @date    2018-06-19 22:51:02
 ///

#include <istream>
#include <string>
#include <iostream>
#include <map>
#include <set>
using std::cout;
using std::endl;
using std::string;
using std::map;
using std::cin;
using std::set;

int main()
{
	map<string, size_t> word_count;

	set<string>exclude = {"The", "But", "and" "or", "An", "A", "the", "but", "And", "Or", "an", "a"};
	
	string word;
	while(cin >> word)
		if(exclude.find(word) == exclude.end())
			++word_count[word];
	for(const auto &w : word_count)
	{		
		cout << w.first << " occurs " << w.second 
			 << ((w.second > 1) ? " times" : " time") << endl;
	}

}
