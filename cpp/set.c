/*************************************************************************
    > File Name: set.c
    > Author: myiuni
    > Mail: 1792526255@qq.com 
    > Created Time: 2020年10月27日 星期二 19时50分27秒
 ************************************************************************/

#include <iostream>
#include <set>
using namespace std;

void printset(set<int>&s)
{
	for (set<int>::iterator it = s.begin(); it != s.end(); it++)
		cout << *it << endl;
}

int main()
{
	set<int> s;
	s.insert(20);
	s.insert(10);
	s.insert(40);
	s.insert(30);
	s.insert(20);

	printset(s);

}

