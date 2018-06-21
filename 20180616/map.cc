 ///
 /// @file    map.cc
 /// @author  LJW
 /// @date    2018-06-20 23:49:25
 ///
 
#include <map>
#include <iostream>
using std::cout;
using std::endl;
using std::pair;
using std::string;
using std::map;

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
	map<int, string> mapIntStr{
		pair<int, string>(1, "beijing"),
		pair<int, string>(2, "shanghai"),
		pair<int, string>(3, "shenzhen"),
		std::make_pair(4, "guangzhou"),
		std::make_pair(3, "hangzhou")
	};
	
	cout << "mapIntStr's size = " << mapIntStr.size() << endl;
	display(mapIntStr);
	//map<int, string>::iterator mit = mapIntStr.begin();
	
	// operator[] : 如果对应的key存在， 就直接返回value的值
	// 否则，则直接创建一个key，对应的value设置为默认值
	//
	cout << mapIntStr[1] << endl; // 通过key值获取value的值
	cout << mapIntStr[2] << endl;
	cout << mapIntStr[0] << endl; // 添加新key:
	mapIntStr[0] = "tianchao";// 既可以修改，也可以添加元素
	mapIntStr[5] = "suzhou"; // 添加元素

	display(mapIntStr);
	
	map<int, string>::iterator it = mapIntStr.find(7);
	if(it != mapIntStr.end())
		cout << it->first << " -- " << it->second << endl;
	else 
		cout << "find failed" << endl;
	// count
	// 
	
#if 0

	while(mit != mapIntStr.end())
	{
		cout << *mit << endl;
	}
#endif
}


void test2()
{
	map<int, string, std::greater<int>> mapIntStr{
		pair<int, string>(1, "beijing"),
		pair<int, string>(2, "shanghai"),
		pair<int, string>(3, "shenzhen"),
		std::make_pair(4, "guangzhou"),
		std::make_pair(3, "hangzhou")
	};
	
	cout << "mapIntStr's size = " << mapIntStr.size() << endl;
	display(mapIntStr);
	//map<int, string>::iterator mit = mapIntStr.begin();
	
	// operator[] : 如果对应的key存在， 就直接返回value的值
	// 否则，则直接创建一个key，对应的value设置为默认值
	//
	cout << mapIntStr[1] << endl; // 通过key值获取value的值
	cout << mapIntStr[2] << endl;
	cout << mapIntStr[0] << endl; // 添加新key:
	mapIntStr[0] = "tianchao";// 既可以修改，也可以添加元素
	mapIntStr[5] = "suzhou"; // 添加元素

	display(mapIntStr);
	
	map<int, string>::iterator it = mapIntStr.find(7);
	if(it != mapIntStr.end())
		cout << it->first << " -- " << it->second << endl;
	else 
		cout << "find failed" << endl;
	// count
	// 
	
#if 0

	while(mit != mapIntStr.end())
	{
		cout << *mit << endl;
	}
#endif
}

void test1()
{
	map<string, string> mapIntStr{
		pair<string, string>("a", "beijing"),
		pair<string, string>("b", "shanghai"),
		pair<string, string>("c", "shenzhen"),
		std::make_pair("d", "guangzhou"),
		std::make_pair("e", "hangzhou")
	};
	
	cout << "mapIntStr's size = " << mapIntStr.size() << endl;
	display(mapIntStr);
	//map<int, string>::iterator mit = mapIntStr.begin();
	
	// operator[] : 如果对应的key存在， 就直接返回value的值
	// 否则，则直接创建一个key，对应的value设置为默认值
	//
	cout << mapIntStr["a"] << endl; // 通过key值获取value的值
	cout << mapIntStr["b"] << endl;
	cout << mapIntStr["c"] << endl; // 添加新key:
	mapIntStr["f"] = "tianchao";// 既可以修改，也可以添加元素
	mapIntStr["e"] = "suzhou"; // 添加元素

	display(mapIntStr);
	
	// pair<string, string> 类型
	pair<map<string, string>::iterator, bool> ret = mapIntStr.insert(pair<string, string>("g", "tianjin"));
	if(ret.second)
	{
		cout << "insert success!" << endl;
	}
	else
		cout << "insert failed" << endl;

	display(mapIntStr);

	map<string, string>::iterator it = mapIntStr.find("a");
	if(it != mapIntStr.end())
		cout << "find it!" << endl <<  it->first << " -- " << it->second << endl;
	else 
		cout << "find failed" << endl;
	// count
	// 
	
#if 0

	while(mit != mapIntStr.end())
	{
		cout << *mit << endl;
	}
#endif
}

// map中可以是任意类型
int main()
{

	test1();
}
