 ///
 /// @file    virtualTable.cc
 /// @author  LJW
 /// @date    2018-06-27 15:49:38
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Base
{
public:
	Base(long base)
	: _base(base)
	{}

	virtual void a() {	cout << "Base::a()" << endl;	}
	virtual void b() {	cout << "Base::b()" << endl;	}
	virtual void c() {	cout << "Base::c()" << endl;	}
private:
	long _base;
};

class Derived
: public Base
{
public:
	Derived(long base, long derived)
	: Base(base)
	, _derived(derived)
	{}

	virtual void a() {	cout << "Derived::a()" << endl;	}
	virtual void b() {	cout << "Derived::b()" << endl;	}
	virtual void c() {	cout << "Derived::c()" << endl;	}
private:
	long _derived;
};


void test()
{
	Derived d(10, 100);
	typedef void(*Function)();

	long ** p = (long **)&d;
	Function f1 = (Function)p[0][0];
	f1();
	
	f1 = (Function)p[0][1];
	f1();
	cout << endl;

	cout << (long)p[1] << endl;
	cout << (long)p[2] << endl;

}

void test1()
{
	Derived derived(10, 100);
	typedef void(*Function)();

	long *pDerived = (long *)&derived;
	
	long *pVatale = (long *)(*(pDerived + 1));

	Function f1 = (Function)(pVatale[0]);
	f1();
	
#if 0
	
	Function f1 = (Function)(pVatale[0] + 1);
	f1();

	f1 = (Function)(pVatale[1]);
	f1();

	f1 = (Function)(pVatale[2]);
	f1();
#endif


}

void test2()
{
	int a[2][3] = {{1, 2, 3},{4, 5, 6}};
	int (*q)[2] = a;
	cout << *q[0] << " " << *q[1] << endl;
//	cout << *(a[1] + 1) << endl;

}

class A
{
private:
	static int a[3];
};
int A::a[3] = {1, 2, 3};

void test3()
{
	A a;
	cout << sizeof(a) << endl;
}

int main()
{
	test2();

}
