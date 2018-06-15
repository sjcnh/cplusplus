 ///
 /// @file    for.cc
 /// @author  LJW
 /// @date    2018-06-15 20:27:41
 ///
#include <vector> 
#include <iostream>
using std::cout;
using std::endl;
using std::vector;

int main()
{
	for(int i : {1, 2, 3, 5, 9})
	{
		cout << i << endl;
	}

	vector<double> vec{1.1, 2.2, 3.3};
	for(auto elem : vec)
	{
		cout << elem << endl;
	}
	return 0;
}
