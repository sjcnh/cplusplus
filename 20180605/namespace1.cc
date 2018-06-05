 ///
 /// @file    namespace.cc
 /// @author  sjcnh(itechie@163.com)
 /// @date    2018-06-05 10:28:46
 ///
 
#include <iostream>
using std::cout;
using std::endl;

namespace A {
	void display()
	{
		cout << "A::display()" << endl;
	}	

} // end of namespace A

namespace B {
	void display(){
		cout << "B::display()" << endl;
	}
} // end of namespace B

int main()
{
	A::display();
	B::display();
	return 0;
}
