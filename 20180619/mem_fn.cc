 ///
 /// @file    mem_fn.cc
 /// @author  LJW
 /// @date    2018-06-23 23:53:18
 ///
 
#include <vector>
#include <algorithm>
#include <functional>
#include <iostream>
using std::cout;
using std::endl;
using std::for_each;
using std::vector;

class Number
{
public:
	Number(int val)
	: _val(val)
	{}

	void display() const
	{
		cout << _val << endl;
	}

	bool isEven() const
	{
		return !(_val % 2);
	}

	bool isPrime() const
	{
		if(_val == 1)
			return false;
		for(int idx = 2; idx != 21; ++idx)
		{
			if(!(_val % idx))
				return false;
		}
		return true;
	}

private:
	int _val;

};

int main()
{
	vector<Number> numbers;
	for(int idx = 1; idx != 21; ++idx)
	{
		numbers.push_back(Number(idx));
	}

	for_each(numbers.begin(), numbers.end(), std::mem_fn(&Number::display));
	cout << endl;

	numbers.erase(
			remove_if(numbers.begin(), numbers.end(), std::mem_fn(&Number::isEven)),
			numbers.end());
	for_each(numbers.begin(), numbers.end(), std::mem_fn(&Number::display));
	cout << endl;

	numbers.erase(
			remove_if(numbers.begin(), numbers.end(), std::mem_fn(&Number::isPrime)),
			numbers.end());
	for_each(numbers.begin(), numbers.end(), std::mem_fn(&Number::display));
	cout << endl;
	

}
