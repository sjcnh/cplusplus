 ///
 /// @file    arrayFind.cc
 /// @author  LJW
 /// @date    2018-06-29 17:05:34
 ///
 
#include <iostream>
#include <vector>
using std::vector;
using std::cout;
using std::endl;


class Solution
{
public:
	bool Find(int target, vector<vector<int>> array)
	{
		if(array.empty())
			return false;

		int i = 0; // row
		int j = array[0].size() - 1; // col
		while(i < (int)array.size() && j >= 0)
		{
			if(target == array[i][j])
				return true;
			else if(array[i][j] > target)
				j--;
			else if(array[i][j] < target)
				++i;
		}
		return false;
	}
};

int main()
{
	vector<vector<int>> array(4); // m

	for(int i = 0; i < 4; ++i)
	{
		array[i].resize(5);
	}	

	int row = array.size();
	int col = array[0].size();
	// 赋值
	//for(int i = 0; i < row; ++i)
	//{
	//	for(int j = 0; j < col; ++j)
	//	{
	//		array[i][j] = (i + 1) * (j + 1); 
	//	}
	//}

	Solution s;
	
	s.Find(1, array) ? cout << "find 6" << endl : cout << "not find" << endl;



}
