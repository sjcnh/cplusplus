 ///
 /// @file    replace2.cc
 /// @author  LJW
 /// @date    2018-06-29 21:29:34
 ///
 
#include <iostream>
using std::cout;
using std::endl;

void replace(char *str, int length)
{
	if(str == NULL || length < 0)
		return ;
	int orignallen = 0;
	int blankCnt = 0;
	while(*str != '\0')
	{
		++orignallen;
		if(*str == ' ')
			++blankCnt;
		++str;
	}
	int newlen = orignallen + 2 * blankCnt;
	int pold = orignallen;
	int pnew = newlen;
	if(pnew + 1 > length)
		return ;
	while(pnew > pold)
	{
		if(str[pold] == ' ')
		{
			str[pnew--] = '0';
			str[pnew--] = '2';
			str[pnew--] = '%';
		}
		else
			str[pnew--] = str[pold];
		pold--;
	}
}

int main()
{
	char str[] = "we are happy";
	replace(str, 30);
	cout << str << endl;

}
