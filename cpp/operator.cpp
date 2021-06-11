/*************************************************************************
    > File Name: operator.cpp
    > Author: myiuni
    > Mail: 1792526255@qq.com 
    > Created Time: 2021年06月11日 星期五 20时57分01秒
 ************************************************************************/

#include <iostream>
using namespace std;

class Person
{
public:

	Person operator+(Person &p)
	{
		Person temp;
		temp.m_a = this->m_a + p.m_a;
		temp.m_b = this->m_b + p.m_b;
		return temp;
	}

	int m_a;
	int m_b;
};

int main()
{
	Person person1;
	person1.m_a = 10;
	person1.m_b = 20;

	Person person2;
	person2.m_a = 30;
	person2.m_b = 40;

	Person person3;
	person3 = person1 + person2;
	cout << "m_a = " << person3.m_a << endl;
	cout << "m_b = " << person3.m_b << endl;

	return 0;
}
