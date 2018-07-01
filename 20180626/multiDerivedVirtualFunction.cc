 ///
 /// @file    multiDerivedVirtualFunction.cc
 /// @author  LJW
 /// @date    2018-06-27 15:01:11
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class A
{
public:
	virtual void a() {	cout << "A::a()" << endl;	}
	virtual void b() {	cout << "A::b()" << endl;	}
	virtual void c() {	cout << "A::c()" <<	endl;	}
};

class B
{
public:
	virtual void a() {	cout << "B::a()" << endl;	}
	virtual void b() {	cout << "B::b()" << endl;	}
	void c() {	cout << "B::c()" << endl;	}
	void d() {	cout << "B::d()" << endl;	}
};

class C
: public A
, public B
{
public: 
	virtual void a() {	cout << "C::a()" << endl;	}
	void c() {	cout << "C::c()" << endl;	}
	void d() {	cout << "C::d()" << endl;	}
};



int main()
{

	C c;
	A *pa = &c;
	pa->a();
	pa->b();
	pa->c();
	cout << endl << endl;

	B *pb = &c;
	pb->a();
	pb->b();
	pb->c();
	pb->d();

	cout << endl << endl;

	c.a();
	c.A::b();
	c.c();
	c.d();
	return 0;
}
