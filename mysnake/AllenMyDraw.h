#pragma once
#include "AllenMap.h"
#include "AllenDraw.h"
#include "AllenShow.h"
/////////////////////////////////////////////
#include <conio.h>
#include <time.h>
#include<iostream>
#include "AllenMap.h"
#include "AllenDraw.h"
#include "AllenSnake.h"
#include "AllenFood.h"
#include "AllenMessageBoxA.h"
class AllenMyDraw
{
public:
	AllenMyDraw();
	~AllenMyDraw();
	void InitSence();
	//���������̰����뵯��
	//void KeyEeventProc(KEY_EVENT_RECORD ker);
	void MouseEventProc(MOUSE_EVENT_RECORD mer);
	//�����������
	void OutputPos(int nX, int nY);
	int MessageLoop();
	void WriteChar(char* psz, int nPosX, int nPosY, WORD wAttr);
	void start();
};

