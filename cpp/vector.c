/*************************************************************************
    > File Name: vector.c
    > Author: myiuni
    > Mail: 1792526255@qq.com 
    > Created Time: 2020年10月26日 星期一 21时21分53秒
 ************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(2);
	v.push_back(2);
	v.push_back(2);
	v.push_back(2);
	v.push_back(2);
	v.push_back(3);

	vector<int>::iterator it;
	for (it = v.begin(); it != v.end(); it++)
		cout << *it << "\t" << endl;

	int num;
	num = count(v.begin(),v.end(),2);
	cout << "num = " << num << endl;

}
