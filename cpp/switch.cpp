/*************************************************************************
    > File Name: switch.cpp
    > Author: myiuni
    > Mail: 1792526255@qq.com 
    > Created Time: 2020年10月19日 星期一 20时17分57秒
 ************************************************************************/

#include <iostream>
using namespace std;

int main()
{
	//1.notify the user to give a score
	//2.user starts 
	//3.give a result according to score
	
	cout << "Please give a score" << endl;

	int score = 0;
	cin >> score;

	cout << "You score is :" << score << endl;

	switch (score)
	{
		case 10:
			cout << "Perfect!" << endl;
			break;
		case 9:
			cout << "wonderful!" << endl;
			break;
		case 8:
			cout << "prety good!" << endl;
			break;
		case 7:
			cout << "Good!" << endl;
			break;
		case 6:
			cout << "just soso" << endl;
			break;
		default:
			cout << "Bad" << endl;
			break;
	}
	return 0;
}
