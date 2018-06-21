 ///
 /// @file   multimultimap.cc
 /// @author  LJW
 /// @date    2018-06-20 23:49:25
 ///
 
#include <map>
#include <iostream>
using std::cout;
using std::endl;
using std::pair;
using std::string;
using std::multimap;

template <typename Container>
void display(const Container &c)
{
	typename Container::const_iterator cit = c.begin();
	while(cit != c.end())
	{
		cout << cit->first << ", " 
			 << (*cit).second << endl;
		++cit;
	}
}

void test0()
{
	multimap<int, string> multimapIntStr{
		pair<int, string>(1, "beijing"),
		pair<int, string>(2, "shanghai"),
		pair<int, string>(3, "shenzhen"),
		std::make_pair(4, "guangzhou"),
		std::make_pair(3, "hangzhou")
	};
	
	cout << "multimapIntStr's size = " << multimapIntStr.size() << endl;
	display(multimapIntStr);
	//multimap<int, string>::iterator mit = multimapIntStr.begin();
	
	// operator[] : 如果对应的key存在， 就直接返回value的值
	// 否则，则直接创建一个key，对应的value设置为默认值
	//

	display(multimapIntStr);
	
	multimap<int, string>::iterator it = multimapIntStr.find(7);
	if(it != multimapIntStr.end())
		cout << it->first << " -- " << it->second << endl;
	else 
		cout << "find failed" << endl;
	// count
	// 
	
#if 0

	while(mit != multimapIntStr.end())
	{
		cout << *mit << endl;
	}
#endif
}


void test2()
{
	multimap<int, string, std::greater<int>> multimapIntStr{
		pair<int, string>(1, "beijing"),
		pair<int, string>(2, "shanghai"),
		pair<int, string>(3, "shenzhen"),
		std::make_pair(4, "guangzhou"),
		std::make_pair(3, "hangzhou")
	};
	
	cout << "multimapIntStr's size = " << multimapIntStr.size() << endl;
	display(multimapIntStr);
	//multimap<int, string>::iterator mit = multimapIntStr.begin();
	
	// operator[] : 如果对应的key存在， 就直接返回value的值
	// 否则，则直接创建一个key，对应的value设置为默认值
	//

	display(multimapIntStr);
	
	multimap<int, string>::iterator it = multimapIntStr.find(7);
	if(it != multimapIntStr.end())
		cout << it->first << " -- " << it->second << endl;
	else 
		cout << "find failed" << endl;
	// count
	// 
	
#if 0

	while(mit != multimapIntStr.end())
	{
		cout << *mit << endl;
	}
#endif
}

void test1()
{
	multimap<string, string> multimapIntStr{
		pair<string, string>("a", "beijing"),
		pair<string, string>("b", "shanghai"),
		pair<string, string>("c", "shenzhen"),
		std::make_pair("d", "guangzhou"),
		std::make_pair("e", "hangzhou"),
		std::make_pair("a", "hangzhou"),
		std::make_pair("b", "hangzhou"),
		std::make_pair("b", "shkj")
	};
	
	cout << "multimapIntStr's size = " << multimapIntStr.size() << endl;
	display(multimapIntStr);
	//multimap<int, string>::iterator mit = multimapIntStr.begin();
	
	// operator[] : 如果对应的key存在， 就直接返回value的值
	// 否则，则直接创建一个key，对应的value设置为默认值
	//

	display(multimapIntStr);
	
	// pair<string, string> 类型
	display(multimapIntStr);

	multimap<string, string>::iterator it = multimapIntStr.find("a");
	pair<multimap<string, string>::iterator, multimap<string, string>::iterator> pit = multimapIntStr.equal_range("b");

	auto range = multimapIntStr.equal_range("a");

	cout << endl << "--------------------------" << endl;
	//for(multimap<string, string>::iterator i = range.first; i != range.second; ++i)
	for(auto i = pit.first; i != pit.second; ++i)
	{
		cout << i->first << " " << i->second << endl;
	}
	cout << endl << "--------------------------" << endl;

	if(it != multimapIntStr.end())
		cout << "find it!" << endl <<  it->first << " -- " << it->second << endl;
	else 
		cout << "find failed" << endl;
	// count
	// 
	
#if 0

	while(mit != multimapIntStr.end())
	{
		cout << *mit << endl;
	}
#endif
}

// multimap中可以是任意类型
int main()
{

	test1();
}
