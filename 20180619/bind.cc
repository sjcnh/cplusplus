 ///
 /// @file    bind.cc
 /// @author  LJW
 /// @date    2018-06-23 22:08:47
 ///
 
#include <functional>
#include <iostream>
using std::bind;
using std::cout;
using std::endl;

void display()
{
	cout << "display()" << endl;

}

// 函数指针
typedef void (*Function)();

struct example
{

	int add(int x, int y)
	{
		cout << "strcut add()" << endl;
		return x + y;
	}

};

void test()
{
	Function f1 = display;
	f1();


}
int add(int x, int y)
{
	cout << "add()" << endl;
	return x + y;

}

void test1()
{
	auto f1 = std::bind(add, 1, 9);
	cout << f1() << endl;

	// bind 占位符
	auto f2 = std::bind(add, 10, std::placeholders::_1);
	cout << f2(9) << endl;

	example e;
	// 绑定一个非静态成员！需要加上地址符号
	// std::bind 绑定成员函数时，必须要在前面加&
	auto f3 = std::bind(&example::add, &e, 1, 9);
	cout << f3() << endl;

	// 绑定函数时，第一个参数可以是对象的地址，也可以是对象本身。
	// std::placeholder::_num, num表示实参传递时，是第几个参数进行传递
	// 
	// 如果有形参不需要进行绑定，则必须用占位符占住该位置
	// 占位符本身所在的位置代表的时形参所在的位置，
	// 占位符的数字代表的时实参传递时的位置
	//
	// std::bind绑定参数时，采用的是值传递的方式
	//
	auto f4 = std::bind(&example::add, example(), 10, std::placeholders::_3);
	cout << "f4() " << f4(1, 10, 33) << endl;

	auto f5 = std::bind(&example::add, std::placeholders::_1, 10, std::placeholders::_2);
	cout << "f5() " << f5(&e, 10, 33) << endl;
	

}

void test2()
{
	// 函数类型的容器, 类模板
	std::function<int()> f1 = std::bind(add, 1, 9); // 注册回调函数
	cout << f1() << endl; // 执行回调函数

	// bind是一个函数模板， bind 占位符
	std::function<int(int)> f2 = std::bind(add, 10, std::placeholders::_1);
	cout << f2(9) << endl;

	example e;
	// 绑定一个非静态成员！需要加上地址符号
	// std::bind 绑定成员函数时，必须要在前面加&
	std::function<int()> f3 = std::bind(&example::add, &e, 1, 9);
	cout << f3() << endl;

	// 绑定函数时，第一个参数可以是对象的地址，也可以是对象本身。
	// std::placeholder::_num, num表示实参传递时，是第几个参数进行传递
	// 
	// 如果有形参不需要进行绑定，则必须用占位符占住该位置
	// 占位符本身所在的位置代表的时形参所在的位置，
	// 占位符的数字代表的时实参传递时的位置
	//
	// std::bind绑定参数时，采用的是值传递的方式
	//
	//placeholder::_num, num的不同，会对function的参数格式造成影响！
	//
	std::function<int(int, int)> f4 = std::bind(&example::add, example(), 10, std::placeholders::_2);
	cout << "f4() " << f4(1, 10) << endl;

	std::function<int(example *, int)> f5 = std::bind(&example::add, std::placeholders::_1, 10, std::placeholders::_2);
	cout << "f5() " << f5(&e, 22) << endl;
	

}
// bind更加灵活，除了普通函数之外，还可以绑定到成员函数
// 
// 
int main()
{
	test2();

}
