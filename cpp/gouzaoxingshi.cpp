/*************************************************************************
    > File Name: gouzaoxingshi.cpp
    > Author: myiuni
    > Mail: 1792526255@qq.com 
    > Created Time: 2020年11月01日 星期日 20时17分43秒
 ************************************************************************/


#include <iostream>
using namespace std;

class Person
{
public:
	//无参构造
	Person()
	{
		cout << "This is no para gouzao" << endl;
	}

	//有参构造
	Person(int age)
	{
//		int m_age = age; 写错的一段代码，m_age成了局部变量。
		m_age = age;
		cout << "Age is :" << m_age << endl;
	}

	//拷贝构造
	Person(const Person& p)
	{
		m_age = p.m_age;
		cout << "拷贝构造的m_age is:" << p.m_age << endl;
	}

	int m_age;

};

int main()
{
	Person p1;

	Person p2(18);

	Person p3(p2);
	cout << p3.m_age <<endl;

}
