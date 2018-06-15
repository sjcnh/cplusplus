 ///
 /// @file    vec.cc
 /// @author  LJW
 /// @date    2018-06-15 22:51:17
 ///
 
#include <vector>
#include <iostream>
using std::cout;
using std::endl;
using std::vector;


int main()
{

	vector<int> vec(10, 1);
	cout<< "addr " << vec.data() << endl;

	return 0;
}
