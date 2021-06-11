/*************************************************************************
    > File Name: testvirtual.cpp
    > Author: myiuni
    > Mail: 1792526255@qq.com 
    > Created Time: 2021年06月11日 星期五 20时02分26秒
 ************************************************************************/

#include <iostream>
#include <string>
using namespace std;

class Shape {
public:
	Shape()
	{
		cout << "This is shape's constructor" << endl;
	}

	void getArea(int length, int width)
	{
		m_length = length;
		m_width = width;
		area = m_length * m_width;
		cout << "area is " << area << endl;
	}

	~Shape()
	{
		cout << "This is destructor" << endl;
	}

private:
	int m_length;
	int m_width;
	int area;
};

class Rectangle : public Shape {	
public:
	Rectangle()
	{
		cout << "This is rectangle's constructor" << endl;
	}

	~Rectangle()
	{
		cout << "This is rectangle's destructor" << endl;
	}
	
};

int main()
{
	Rectangle rect;
	return 0;
}
