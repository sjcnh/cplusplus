 ///
 /// @file    MinNumberInRotateArray.cc
 /// @author  LJW
 /// @date    2018-07-05 22:09:26
 ///
 
#include <iostream>
#include <vector>
using std::vector;
using std::cout;
using std::endl;

class Solution
{
public:
	int MinNumberInRotateArray(vector<int> rotateArray)
	{
		int size = rotateArray.size();
		if(0 == size)
			return -1;
		int left = 0, right = size - 1;
		int mid = left; // 考虑0个元素搬动，即原排序数组为旋转数组，那么0元素即为最小值
		while(rotateArray[left] >= rotateArray[right])
		{
			if(right - left == 1) // 两个指针相邻，那么后者为最小值
			{
				mid = right;
				break;
			}
			mid = (left + right) / 2; // mid 一直变化条件 
			// 如果left\right\mid都相等，则需要顺序遍历找到最小值
			if(rotateArray[left] == rotateArray[right] && rotateArray[left] == rotateArray[mid])
			{
				return MinOrder(rotateArray, left, right);
			}
			// 必须考虑相等
			if(rotateArray[mid] >= rotateArray[left])
				left = mid;
			else
				right = mid;
		}
		return rotateArray[mid];
	}

private:
	int MinOrder(vector<int> &num, int left, int right)
	{
		int ret = num[left];
		for(int i = left; i != right; ++i)
		{
			if(num[left] < ret)
				ret = num[left];
		}
		return ret;
	}
};


int main()
{
	Solution s;
	vector<int> vec = {3, 4, 5, 1, 2};
	vector<int> vec1 = {3, 2, 3, 0, 2};
	cout << "the min num is " << s.MinNumberInRotateArray(vec1) << endl;

	return 0;
}
