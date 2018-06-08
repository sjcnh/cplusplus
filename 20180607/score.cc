 ///
 /// @file    score.cc
 /// @author  sjcnh(itechie@163.com)
 /// @date    2018-06-07 20:48:29
 ///
#include <vector> 
#include <iostream>
using std::cin;
using std::vector;
using std::cout;
using std::endl;

int main()
{
	vector<unsigned> scores(11, 0);
	unsigned grade;
	while(cin >> grade)
	{
		if(grade <= 100)
			++scores[grade/10];
	}
	for(auto i : scores)
	{
		cout << i << " ";
	}
	cout << endl;
}
