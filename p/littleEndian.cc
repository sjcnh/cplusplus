 ///
 /// @file    littleEndian.cc
 /// @author  LJW
 /// @date    2018-07-10 12:29:35
 ///
 
#include <iostream>
using std::cout;
using std::endl;

static bool isLittleEndian()
{
	return __BYTE_ORDER == __LITTLE_ENDIAN;
}

int main()
{
	if(isLittleEndian())
		cout << "This system is little endian" << endl;
	else
		cout << "this system is big endian" << endl;

}
