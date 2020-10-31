/*************************************************************************
    > File Name: speechManager.h
    > Author: myiuni
    > Mail: 1792526255@qq.com 
    > Created Time: 2020年10月31日 星期六 14时54分52秒
 ************************************************************************/

#pragma once
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <map>
#include <algorithm>
#include "speaker.h"
using namespace std;

class SpeechManager
{
public:
	SpeechManager();

	void show_Menu();

	void exitSystem();

	void startSpeech();

	void speechDraw();

	~SpeechManager();

	void initSpeech();

	void createSpeaker();

	vector<int>v1;

	vector<int>v2;
	
	vector<int>vVictory;

	map<int, Speaker>m_Speaker;

	int m_Index;
};

