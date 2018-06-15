 ///
 /// @file    log4cpp.cc
 /// @author  LJW
 /// @date    2018-06-13 20:04:51
 ///

#include <log4cpp/Category.hh>
#include <log4cpp/PatternLayout.hh>
#include <log4cpp/FileAppender.hh>
#include <log4cpp/RollingFileAppender.hh>
#include <log4cpp/Priority.hh>
#include <sstream>
#include <iostream>
using std::cout;
using std::endl;
using namespace log4cpp;

int main()
{
	PatternLayout * ptnLayout1 = new PatternLayout();
	ptnLayout1->setConversionPattern("%d [%p] %m %n");

	PatternLayout *ptnLayout2 = new PatternLayout();
	ptnLayout2->setConversionPattern("%d [%p] %m %n");
	
	FileAppender *fileAppender = new FileAppender("fileAppender", "wangdao.txt");
	fileAppender->setLayout(ptnLayout1);

	RollingFileAppender * rollingfileAppender = new RollingFileAppender("rollingfileAppender", "rolltest.txt", 5 * 1024);
	rollingfileAppender->setLayout(ptnLayout2);

	Category &root = Category::getRoot().getInstance("root");
	root.addAppender(fileAppender);
	root.addAppender(rollingfileAppender);
	root.setPriority(Priority::DEBUG);

	for(int idx = 0; idx != 100; ++idx)
	{
		std::ostringstream oss;
		oss << "this is " << idx << " line message";
		root.error(oss.str());
	}
	Category::shutdown();
	return 0;
}
