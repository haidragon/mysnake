#pragma once
#include <windows.h>
#include<cstdio>
class AllenDraw
{
public:
	AllenDraw();
	~AllenDraw();
	// 指定位置输出字符（串）
	void WriteChar(char* psz, int nPosX, int nPosY, WORD wAttr);
};

