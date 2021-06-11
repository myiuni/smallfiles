/*************************************************************************
    > File Name: templatefunction.cpp
    > Author: myiuni
    > Mail: 1792526255@qq.com 
    > Created Time: 2021年06月11日 星期五 20时13分59秒
 ************************************************************************/

#include <iostream>
using namespace std;

template <typename T>

T m_min(T x, T y)
{
	return x < y ? x : y;
}

int main(int argc, char *argv[])
{
	double a = 1.7;
	double b = 0.5;
	double c;
	c = m_min(a,b);
	cout << "c = " << c << endl;
	
	return 0;
}
