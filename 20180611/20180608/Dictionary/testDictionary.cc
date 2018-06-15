 ///
 /// @file    testDictionary.cc
 /// @author  LJW
 /// @date    2018-06-13 19:47:43
 ///

#include "Dictionary.h"
#include <iostream>
using std::cout;
using std::endl;

int main()
{
	Dictionary dict;
	dict.read("The_Holy_Bible.txt");
	dict.store("dictionary.txt");
	return 0;
}
