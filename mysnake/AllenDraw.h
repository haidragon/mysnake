#pragma once
#include <windows.h>
#include<cstdio>
class AllenDraw
{
public:
	AllenDraw();
	~AllenDraw();
	// ָ��λ������ַ�������
	void WriteChar(char* psz, int nPosX, int nPosY, WORD wAttr);
};

