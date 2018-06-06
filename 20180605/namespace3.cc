///
/// @file    namespace.cc
/// @author  sjcnh(itechie@163.com)
/// @date    2018-06-05 10:28:46
///

#include <iostream>
using std::cout;
using std::endl;

namespace B {
	void display(){
		cout << "B::display()" << endl;
	}
	void show()
	{
		cout << "B::show()" << endl;
	}		
} // end of namespace B

namespace A {
	void display()
	{
		cout << "A::display()" << endl;
		B::show();// 在函数里面调用B的show函数
	}	
	namespace C 
	{
		void display()
		{
			cout << "C::display()" << endl;
		}	
	}

} // end of namespace A


int main()
{
	A::display();
	B::display();
	A::C::display();
	return 0;
}
