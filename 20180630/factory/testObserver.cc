 ///
 /// @file    testObserver.cc
 /// @author  LJW
 /// @date    2018-07-02 21:01:55
 ///
 
#include "observer.h"
#include <memory>
#include <iostream>
using std::cout;
using std::endl;
using std::unique_ptr;

int main()
{
	unique_ptr<Subject> subject(new ConcreteSubject());
	unique_ptr<Observer> ob1(new ConcreteObserver(subject.get()));
	unique_ptr<Observer> ob2(new ConcreteObserver(subject.get()));
	unique_ptr<Observer> ob3(new ConcreteObserver(subject.get()));
	unique_ptr<Observer> ob4(new ConcreteObserver(subject.get()));

	subject->attach(ob1.get());
	subject->attach(ob2.get());
	subject->attach(ob3.get());
	subject->attach(ob4.get());

	subject->setState(1);
	subject->dettach(ob1.get());
	cout << endl << endl;
	subject->setState(2);
	return 0;

}

