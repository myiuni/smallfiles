/*************************************************************************
    > File Name: gouzaochushihua.cpp
    > Author: myiuni
    > Mail: 1792526255@qq.com 
    > Created Time: 2020年11月01日 星期日 20时33分51秒
 ************************************************************************/

#include <iostream>
#include <string>
using namespace std;

class Person
{
public:
	Person(string name, int age, int height):m_name(name), m_age(age), m_height(height) {};

	string m_name;
	int m_age;
	int m_height;
};

int main()
{
	Person p("zhang san", 20, 190);
	cout << p.m_name << " " << p.m_age << " " << p.m_height <<endl;
}
