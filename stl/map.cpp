/*************************************************************************
    > File Name: map.c
    > Author: myiuni
    > Mail: 1792526255@qq.com 
    > Created Time: 2020年09月06日 星期日 19时58分31秒
 ************************************************************************/

#include <iostream>
#include <map>
#include <string>
using namespace std;

int func()
{
	map<int, string> map1;
	map1.insert(make_pair(1,"teacker01"));
	map1.insert(make_pair(2,"teacker02"));
	map1.insert(make_pair(3,"teacker03"));

	map<int, string>::iterator it;
	for (it = map1.begin(); it != map1.end(); it++) {
		cout << it->first << "\t" << it->second << endl;
	}

	it = map1.find(2);
	cout << it->first << "\t" << it->second << endl;

	while (!map1.empty()) {
		map<int, string>::iterator it = map1.begin();
		cout << it->first << "\t" << it->second << endl;
		map1.erase(it);
	}

}

int main()
{
	cout << "run the func !" << endl;
	func();
	cout << "Done!" << endl;

}
