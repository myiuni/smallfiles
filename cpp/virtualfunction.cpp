/*************************************************************************
    > File Name: virtualfunction.cpp
    > Author: myiuni
    > Mail: 1792526255@qq.com 
    > Created Time: 2021年06月10日 星期四 20时23分04秒
 ************************************************************************/

#include <iostream>
#include <string>
using namespace std;

class Father
{
public:
	Father(int age)
	{
		m_age = age;
		cout << "Father's age is " << m_age << endl;
	}

	void nousefunction()
	{
		cout << "this is a no use function" << endl;
	}

	virtual ~Father()
	{
		cout << "this is Father's destructor" << endl;
	}

private:
	int m_age;
};

class Son : public Father
{
public:
	Son() : Father(40)
	{
		cout << "This is son" << endl;
	}

	~Son()
	{
		cout << "This is son destructor" << endl;
	}

};

int main()
{
	Son son;
	son.nousefunction();
	return 0;
}
