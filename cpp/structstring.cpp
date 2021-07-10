/*************************************************************************
    > File Name: structstring.cpp
    > Author: myiuni
    > Mail: 1792526255@qq.com 
    > Created Time: 2021年07月10日 星期六 10时32分16秒
 ************************************************************************/

#include <iostream>
using namespace std;

struct HelpInfo {
	string cmd;
	string tip;
};

struct HelpInfo arr[] = {
	{"1", "This is a"},
	{"2", "This is b"},
	{"3", "This is c"},
	{"4", "This is d"},
};

int main()
{
	int len = sizeof(arr)/sizeof(arr[0]);
	for (int i = 0; i < len; i++)
		cout << arr[i].cmd << "--->" << arr[i].tip << endl;
}
