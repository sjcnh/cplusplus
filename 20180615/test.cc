 ///
 /// @file    test.cc
 /// @author  LJW
 /// @date    2018-06-15 19:55:15
 ///

#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>

using std::cout;
using std::endl;
using std::vector;
using namespace std;

int main()
{

	int ia[6] = {27, 210, 12, 45, 100, 99};
	vector<int, allocator<int>> vi(ia, ia + 6);
	cout << count_if(vi.begin(), vi.end(), 
			not1(bind2nd(less<int>(), 40)));
	
	return 0;
}
