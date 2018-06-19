 ///
 /// @file    operator[].cc
 /// @author  LJW
 /// @date    2018-06-17 16:15:11
 ///
 
#include <iostream>
using std::cout;
using std::endl;


class CharArray
{
public;
	CharArray(int size)
	: _size(size)
	, _data(new char[_size]()
	{}

	char & operator[](size_t idx)
	{
		static char nullchar = '\0';
		if(idx >= _size)
			return nullchar;
		return _data[idx];
	}

	void print() const
	{

		cout << _data << endl;
	}

	~CharArray()
	{
		delete []_data;
	}

private:
	size_t _size;
	char * _data;

};

int main()
{

}
