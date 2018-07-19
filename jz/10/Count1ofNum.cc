 ///
 /// @file    Count1ofNum.cc
 /// @author  LJW
 /// @date    2018-07-11 15:00:08
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Solution
{
public:
	int Count1ofNum(int n)
	{
		int cnt = 0;
		while(n)
		{
			++cnt;
			n &= (n - 1);
		}
		return cnt;
	}
};

int main()
{
	int i = 0;
	std::cin >> i;
	cout << "sizeof(Solution)" << sizeof(Solution) << endl;
	Solution *s = new Solution();
	cout << "count 1 of num is " << s->Count1ofNum(i) << endl;
}
