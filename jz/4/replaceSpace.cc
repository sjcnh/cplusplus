 ///
 /// @file    replaceSpace.cc
 /// @author  LJW
 /// @date    2018-06-29 20:20:49
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Solution
{
public:
	void replaceSpace(char *str, int length) // length是原始数组内存空间总大小
	{
		// 判空 or length < 0
		if(NULL == str || length < 0)
			return;
		int oldStrLen = 0;
		int blankCnt = 0;
		int newStrLen = 0;
		while(*str != '\0')
		{
			++oldStrLen;
			if(*str == ' ')
				++blankCnt;
			++str;
		}
		newStrLen = oldStrLen + 2 * blankCnt + 1;// \0 问题
		cout << oldStrLen << endl;
		cout << newStrLen << endl;
		if(newStrLen> length)
			return;
		str[newStrLen--] = '\0';
		while(newStrLen> oldStrLen) 
		{
			if(str[oldStrLen] == ' ') // 注意，原来指针要变化！
			{
				str[newStrLen--] = '0';
				str[newStrLen--] = '2';
				str[newStrLen--] = '%';
			}
			else
			{
				str[newStrLen--] = str[oldStrLen]; 
			}
			oldStrLen--;
		}
	}
};

int main()
{
	char str[30] = "we are happy";
	char str1[30] = " we are happy ";
	char str2[30] = "  three blank";
	Solution s;
	s.replaceSpace(str, 30);
	s.replaceSpace(str1, 30);
	s.replaceSpace(str2, 30);
	cout << str << endl;
	cout << str1 << endl;
	cout << "lllllllllll" << endl;
	cout << str2 << endl;

	return 0;
}
