 ///
 /// @file    Student.cc
 /// @author  sjcnh(itechie@163.com)
 /// @date    2018-06-08 11:32:32
 ///

#include <stdlib.h>
#include <string.h>
#include <iostream>
using std::cout;
using std::endl;

class Student
{

	public:
		Student(int id, const char * name)
		: _id(id)
		, _name(new char[strlen(name) + 1]())
		{
			cout << "Student(int, const char *)" << endl;
			strcpy(_name, name);
		}
		~Student()
		{
			delete [] _name;

			cout << "~Student()" << endl;
		}

		void print() const
		{
			cout << "id:" << _id << endl
				 << "name:" << _name << endl;
		}
	// 只能生成栈对象，把operator new/delete放在private区域
	private:
		void * operator new(size_t sz); // 系统中有，自己重载该方法
		void operator delete(void * ret);

	private:
		int _id;
		char * _name;
};

int main()
{
	// 只能生成栈对象
	Student s1(101, "Rose"); // 编译通过
	s1.print();
	cout << endl;
#if 0
	Student *pstu = new Student(100, "jake"); // 编译不通过
	pstu->print();

	delete pstu;
#endif
	return 0;
}
