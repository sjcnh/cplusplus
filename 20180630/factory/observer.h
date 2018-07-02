 ///
 /// @file    observer.cc
 /// @author  LJW
 /// @date    2018-07-02 20:06:15
 ///
 
#ifndef __LJ_OBSERVER_H_
#define __LJ_OBSERVER_H_

#include <iostream>
#include <list>
using std::cout;
using std::list;
using std::endl;

class Observer
{
public:
	Observer() {	cout << "Observer()" << endl;	}	
	virtual void update() = 0;
	virtual ~Observer(){	cout << "~Observer()" << endl;	}
};

class Subject;

typedef int State;

class ConcreteObserver
: public Observer
{
public:
	ConcreteObserver(Subject *);
	void update();
	virtual ~ConcreteObserver();

private:
	Subject *_subject;
	State _obState;
};



class Subject
{
public:
	Subject();
	void attach(Observer *);
	void dettach(Observer *);
	virtual void notify();

	virtual void setState(State state);
	virtual State getState() const;
	virtual ~Subject();
protected:
	list<Observer *> _obList;
	State _subjectState;
};

class ConcreteSubject
: public Subject
{
public:
	ConcreteSubject();
	~ConcreteSubject();
	virtual void setState(State state);
	virtual State getState() const;
};

#endif
