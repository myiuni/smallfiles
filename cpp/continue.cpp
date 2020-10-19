/*************************************************************************
    > File Name: continue.cpp
    > Author: myiuni
    > Mail: 1792526255@qq.com 
    > Created Time: 2020年10月19日 星期一 20时45分25秒
 ************************************************************************/
#include <iostream>
using namespace std;

int main()
{
	int i;
	for (i = 0; i < 10; i++) {
		if (i % 2 == 0)
			continue; //contine don't execute the next command and do the next while
		cout << "i = " << i << endl;
	}
}
