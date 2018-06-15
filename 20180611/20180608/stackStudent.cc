 ///
 /// @file    stackStudent.cc
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
	
	~Student()
	{
		delete []_name;
		cout << "~Student()" << endl;
	}
// 只能生成栈对象： 把operator new/delete 放在private区域
private:
	void * operator new(size_t sz);
	void operator delete(void *ret);
private:
	int _id;
	char *_name;
};

int main()
{
	Student s1(101, "Rose"); // 编译通过
	s1.print();
	cout << endl;
#if 0	
	Student * pstu = new Student(100, "Jake"); // 编译不通过
	pstu->print();

	delete pstu;
#endif
	return 0;

}
