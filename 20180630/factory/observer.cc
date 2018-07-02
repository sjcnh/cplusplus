 ///
 /// @file    observer.cc
 /// @author  LJW
 /// @date    2018-07-02 20:16:37
 ///
 
#include "observer.h"
#include <algorithm>

ConcreteObserver::ConcreteObserver(Subject *subject)
: _subject(subject)
, _obState(-1)
{
	cout << "ConcreteObserver()" << endl;
}

void ConcreteObserver::update()
{
	State subjectState = _subject->getState();
	if(subjectState !=  _obState)
	{
		_obState = subjectState;
		cout << " update state " << _obState << endl;
	}
}

ConcreteObserver::~ConcreteObserver()
{
	cout << "~ConcreteObserver()" << endl;
}

void Subject::attach(Observer *ob)
{
	auto iter = std::find(_obList.begin(), _obList.end(), ob);
	if(iter != _obList.end())
	{
		_obList.push_back(ob);
	}

}

void Subject::dettach(Observer *ob)
{
	auto iter = std::find(_obList.begin(), _obList.end(), ob);
	if(iter != _obList.end())
	{
		_obList.push_back(ob);
	}

}

void Subject::notify()
{
	cout << "notify all observer" << endl;
	for(auto ob : _obList)
	{
		ob->update();
	}
}

void Subject::setState(State state)
{
	_subjectState = state;
}

State Subject::getState() const
{
	return _subjectState;
}

Subject::Subject()
{
	cout << "Subject()" << endl;
}

Subject::~Subject()
{
	cout << "~Subject()" << endl;
}

void ConcreteSubject::setState(State state)
{
	_subjectState = state;
	notify();
}

State ConcreteSubject::getState() const
{
	return _subjectState;
}

ConcreteSubject::ConcreteSubject()
{
	cout << "ConcreteSubject()" << endl;
}

ConcreteSubject::~ConcreteSubject()
{
	cout << "~ConcreteSubject()" << endl;
}

