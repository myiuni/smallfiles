/*************************************************************************
    > File Name: manager.cpp
    > Author: myiuni
    > Mail: 1792526255@qq.com 
    > Created Time: 2020年10月31日 星期六 15时01分53秒
 ************************************************************************/

#include <iostream>
#include <string>
#include "speechManager.h"
using namespace std;

int main()
{
	SpeechManager sm;

/*
	for (map<int, Speaker>::iterator it = sm.m_Speaker.begin(); it != sm.m_Speaker.end(); it++)
	{
		cout << "选手编号：" << it->first << "姓名：" << it->second.m_Name << "分数：" << it->second.m_Score << endl;
	}
*/
	int choice = 0;

	while (true) {
		sm.show_Menu();

		cout << "请输入你的选择：" << endl;
		cin >> choice;

		switch (choice)
		{
			case 1:
				sm.startSpeech();
				break;
			case 2:
				break;
			case 3:
				break;
			case 0:
				sm.exitSystem();
				break;
			default:
				system("cls");
				break;
		}

	}


	return 0;
}
