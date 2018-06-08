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

		// 重载
		void * operator new(size_t sz)
		{
			cout << "void * operator new(size_t)" << endl;
			void * ret = malloc(sz);
			return ret;
		}

		void operator delete(void * ret)
		{
			free(ret);
			cout << "void operator delete(void *)" << endl;
		}

	private:
		int _id;
		char * _name;
};

int main()
{
	Student *pstu = new Student(100, "jake");
	pstu->print();

	delete pstu;
	return 0;
}
