#pragma once
#pragma comment(lib,"winmm.lib")
#include<Windows.h>
#include<iostream>
#include "AllenSence.h"
#include "AllenSimpleSence.h"
#include "AllenMediumSence.h"
#include "AllenDifficutSence.h"
#include "AllenShow.h"
#include "AllenCustomSence.h"

class AllenDelegate
{
public:
	//��ȡ����
	static AllenDelegate* getInstance();
	void initmysnake();
	~AllenDelegate();
private:
	AllenDelegate();
	//�Ѹ��ƹ��캯����=������Ҳ��Ϊ˽��,��ֹ������
	AllenDelegate(const AllenDelegate&);
	AllenDelegate& operator=(const AllenDelegate&);
	//Ψһ������
	static AllenDelegate* instance;
};

