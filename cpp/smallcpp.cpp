/*************************************************************************
    > File Name: smallcpp.cpp
    > Author: myiuni
    > Mail: 1792526255@qq.com 
    > Created Time: 2021年06月10日 星期四 20时09分31秒
 ************************************************************************/

#include <iostream>
#include <string>
using namespace std;

class Tom
{
public:
	Tom()
	{
		cout << "This is tom" << endl;
	}

	void getName(string name)
	{
		m_name = name;
		cout << "Tom's name is" << m_name << endl;
	}

	void getAge(int age)
	{
		m_age = age;
		cout << "Tom's age is " << age << endl;
	}

private:
	int m_age;
	string m_name;

};

int main()
{
	Tom tom;
	cout << "sizeof(tom) is: " << sizeof(tom) << endl;
	tom.getName("jake");
	tom.getAge(18);
	return 0;
}
