/*************************************************************************
    > File Name: list-sort-class.cpp
    > Author: myiuni
    > Mail: 1792526255@qq.com 
    > Created Time: 2020年10月28日 星期三 20时29分09秒
 ************************************************************************/

#include <iostream>
#include <list>
#include <string>
using namespace std;

class Person
{
public:
	Person(string name, int age, int height)
	{
		m_name = name;
		m_age = age;
		m_height = height;
	}

	string m_name;
	int m_age;
	int m_height;

};

bool compare(Person &p1, Person &p2)
{
	return p1.m_age < p2.m_age;
}
int main()
{
	list<Person> p;
	Person person1("Liubei", 30, 170);
	Person person2("Guanyu", 32, 170);
	Person person3("Zhangfei", 28, 170);

	list<Person>::iterator it;


	p.push_back(person1);
	p.push_back(person2);
	p.push_back(person3);

	for (it = p.begin(); it != p.end(); it++)
		cout << "name is:" << it->m_name << " age is:" << it->m_age << " height is:" << it->m_height << endl;

	p.sort(compare);

	for (it = p.begin(); it != p.end(); it++)
		cout << "name is:" << it->m_name << " age is:" << it->m_age << " height is:" << it->m_height << endl;


	

}
