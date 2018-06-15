 ///
 /// @file    heapStudent.cc
 /// @author  LJW
 /// @date    2018-06-13 21:39:47
 ///

#include <string.h>
#include <stdlib.h>
#include <iostream>
using std::cout;
using std::endl;

class Student
{
public:
	Student(int id, const char *name)
	: _id(id)   // 顺序和声明时一样！
	, _name(new char[strlen(name) + 1]())
	{
		cout << "Student(int, const char*)" << endl;
		strcpy(_name, name);
	}

	void print() const  // 不改变时加const
	{
		cout << "id: " << _id << endl
			 << "name: " << _name << endl;
	}
	
	void destroy()
	{
		delete this;
	}
// 只能生成堆对象：将析构函数私有化，
// 但是堆对象的回收需要在类内定义一个销毁函数

private:
	~Student()
	{
		delete []_name;
		cout << "~Student()" << endl;
	}
public:
	// 重载
	void * operator new(size_t sz)
	{
		cout << "void * operator new(size_t) " << endl;
		void *ret = malloc(sz);
		return ret;
	}

	void operator delete(void *ret)
	{
		free(ret);
		cout << "void operator delete(void *)" << endl;
	}
private:
	int _id;
	char *_name;
};

int main()
{
#if 0
	// 栈对象的生成同时需要构造函数和析构函数都是public
	Student s1(101, "Rose"); // 编译不通过
	s1.print();
#endif
	Student * pstu = new Student(100, "Jake"); // 编译通过
	pstu->print();

	cout << endl;
	// delete pstu;
	pstu->destroy();
	return 0;

}
