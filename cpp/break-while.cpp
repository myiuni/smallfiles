/*************************************************************************
    > File Name: break-while.cpp
    > Author: myiuni
    > Mail: 1792526255@qq.com 
    > Created Time: 2020年10月19日 星期一 20时39分16秒
 ************************************************************************/
#include <iostream>
using namespace std;

int main()
{
	int i;
	for (i = 0; i < 10; i++) {
		if (i == 5)
			break;
		cout << "i= " << i << endl;
	}
}
