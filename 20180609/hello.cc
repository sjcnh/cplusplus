 ///
 /// @file    hello.cc
 /// @author  sjcnh(itechie@163.com)
 /// @date    2018-06-09 11:14:55
 ///
 
#include <iostream>
#include <log4cpp/Category.hh>
#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/BasicLayout.hh>
#include <log4cpp/Priority.hh>

using namespace std;
using std::cout;
using std::endl;

int main()
{
	log4cpp::OstreamAppender* osAppender = new log4cpp::OstreamAppender("osAppender", &cout);
	osAppender->setLayout(new log4cpp::BasicLayout());

	log4cpp::Category &root = log4cpp::Category::getRoot();
	//root.addAppender(osAppender);
	root.setAppender(osAppender);
	root.setPriority(log4cpp::Priority::DEBUG);

	root.error("Hello log4cpp in a Error Message!");
	root.warn("Hello log4cpp in a Warning Message!");
	root.debug("heeee in DEBUG");
	log4cpp::Category::shutdown();
	return 0;

		
}
