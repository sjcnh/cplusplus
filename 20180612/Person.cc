 ///
 /// @file    Person.cc
 /// @author  LJW
 /// @date    2018-06-17 13:59:54
 ///
 
#include <iostream>
using std::cout;
using std::endl;

template<class T>
class Person
{
public:
	Person(T id, T age)
	: _id(id)
	, _age(age)
	{
		cout << " Person() " << endl;
	}

	void display()
	{
		cout <<"id:" << _id << "age: " << _age << endl;
	}

private:
	T _id;
	T _age;

};

int main()
{
	Person<int> p(10, 22);
	p.display();	

	return 0;
	
}
