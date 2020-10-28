/*************************************************************************
    > File Name: stl-list-reverse.cpp
    > Author: myiuni
    > Mail: 1792526255@qq.com 
    > Created Time: 2020年10月28日 星期三 20时22分28秒
 ************************************************************************/

#include <iostream>
#include <list>
#include <string>
using namespace std;

int main()
{
	list<int> l;
	l.push_back(3);
	l.push_back(6);
	l.push_back(7);
	l.push_back(9);
	l.push_back(2);

	list<int>::iterator it;
	cout << "Before is:" << endl;
	for (it = l.begin(); it != l.end(); it++)
		cout << *it << " ";
	cout << endl;
	l.reverse();
	cout << "After is:" << endl;
	for (it = l.begin(); it != l.end(); it++)
		cout << *it << " ";
	cout << endl;
}
