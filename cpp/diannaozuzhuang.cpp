/*************************************************************************
    > File Name: diannaozuzhuang.cpp
    > Author: myiuni
    > Mail: 1792526255@qq.com 
    > Created Time: 2020年11月14日 星期六 09时29分28秒
 ************************************************************************/

#include <iostream>
using namespace std;

class CPU
{
public:
	virtual void calculate() = 0;
};

class VideoCard
{
public:
	virtual void display() = 0;

};

class Memory
{
public:
	virtual void storage() = 0;
};

class Computer
{
public:
	Computer(CPU *cpu, VideoCard *vc, Memory *mem)
	{
		m_cpu = cpu;
		m_vc = vc;
		m_mem = mem;
	}

	~Computer()
	{
		if (m_cpu != NULL)
		{
			delete m_cpu;
			m_cpu = NULL;
		}

		if (m_vc!= NULL)
		{
			delete m_vc;
			m_vc= NULL;
		}

		if (m_mem!= NULL)
		{
			delete m_mem;
			m_mem= NULL;
		}
	}

	void work()
	{
		m_cpu->calculate();
		m_vc->display();
		m_mem->storage();
	}

private:
	CPU *m_cpu;
	VideoCard *m_vc;
	Memory *m_mem;
};

//intel
class IntelCPU : public CPU
{
public:
	virtual void calculate()
	{
		cout << "Intel cpu is running!" << endl;
	}

};

class IntelVideoCard : public VideoCard
{
public:
	virtual void display()
	{
		cout << "Intel VideoCard is displaying!" << endl;
	}

};

class IntelMemory : public Memory
{
public:
	virtual void storage()
	{
		cout << "Intel Memory is storaging!" << endl;
	}
};


class LenovoCPU : public CPU
{
public:
	virtual void calculate()
	{
		cout << "Lenovo cpu is running!" << endl;
	}

};

class LenovoVideoCard : public VideoCard
{
public:
	virtual void display()
	{
		cout << "Lenovo VideoCard is displaying!" << endl;
	}

};

class LenovoMemory : public Memory
{
public:
	virtual void storage()
	{
		cout << "Lenovo Memory is storaging!" << endl;
	}
};

void test01()
{
	CPU *intelCpu = new IntelCPU;
	VideoCard * intelCard = new IntelVideoCard;
	Memory * intelMem = new IntelMemory;

	Computer *computer1 = new Computer(intelCpu, intelCard, intelMem);
	computer1->work();
	delete computer1;

	Computer *computer2 = new Computer(new LenovoCPU, new LenovoVideoCard, new LenovoMemory);
	computer2->work();
	delete computer2;
}

int main()
{
	test01();
}
