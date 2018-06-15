 ///
 /// @file    testMylog.cc
 /// @author  LJW
 /// @date    2018-06-13 20:36:47
 ///

#include "Mylog.h"
#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::endl;

void test0()
{
	wd::Mylog::getInstance()->warn("this is warn msg");
	wd::Mylog::getInstance()->info("this is info msg");
	wd::Mylog::getInstance()->error("this is error msg");
	wd::Mylog::getInstance()->debug("this is debug msg");
}

void test1()
{
	cout << __FILE__ << endl
		 << __LINE__ << endl
		 << __FUNCTION__ << endl;
}


void test2()
{
	wd::Mylog::getInstance()->warn(prefix("this is warn msg"));
	wd::Mylog::getInstance()->info(prefix("this is info msg"));
	wd::Mylog::getInstance()->error(prefix("this is error msg"));
	wd::Mylog::getInstance()->debug(prefix("this is debug msg"));
	

}

void test3()
{
	LogWarn("this is warn msg");
	LogInfo("this is info msg");
	LogError("this is error msg");
	LogDebug("this is debug msg");
}

int main()
{
//	test0();
	test1();
	cout << endl;
	test2();
	cout << endl;
	test3();
}
