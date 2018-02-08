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
	//获取单例
	static AllenDelegate* getInstance();
	void initmysnake();
	~AllenDelegate();
private:
	AllenDelegate();
	//把复制构造函数和=操作符也设为私有,防止被复制
	AllenDelegate(const AllenDelegate&);
	AllenDelegate& operator=(const AllenDelegate&);
	//唯一个对象
	static AllenDelegate* instance;
};

