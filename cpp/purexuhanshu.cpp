/*************************************************************************
    > File Name: purexuhanshu.cpp
    > Author: myiuni
    > Mail: 1792526255@qq.com 
    > Created Time: 2020年11月07日 星期六 08时45分29秒
 ************************************************************************/

#include <iostream>
using namespace std;

class Base
{
public:
	//无法实例化对象
	//子类必须重写父类纯虚函数
	virtual void func() = 0;
};

class son:public Base
{
	void func()
	{
		cout << "This is chong xie de hanshu" << endl;
	}
};

int main()
{
	//new 加括号和不加括号的区别
	Base *base = new son;
	base->func();
}


