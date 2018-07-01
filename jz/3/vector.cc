 ///
 /// @file    vector.cc
 /// @author  LJW
 /// @date    2018-06-29 16:51:13
 ///
 
#include <iostream>
#include <vector>
using std::vector;
using std::cout;
using std::endl;

int main()
{
	vector<vector<int>> array(3); // m
	// 初始化一个m*n二维数组
	for(int i = 0; i < 3; ++i)
	{
		array[i].resize(4);  // n
	}
	
	int row = array.size();
	int col = array[0].size();

	// 赋值
	for(int i = 0; i < row; ++i)
	{
		for(int j = 0; j < col; ++j)
		{
			array[i][j] = (i + 1) * (j + 1); 
		}
	}

	 
	// 输出二位数组的行列
	cout << "Row: " << row << " Column:" << col << endl;

	// 输出二位数组
	cout << "[" << endl;
	for(int i = 0; i < row; ++i)
	{
		cout << "[" << " ";
		for(int j = 0; j < col; ++j)
		{
			cout << array[i][j] << " ";
		}
		cout << "]" << endl;
	}
	cout << "]" << endl;

	return 0;
}
