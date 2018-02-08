#include "AllenPoint.h"
//#include "tools.h"
#include <windows.h>
#include <stdio.h>
#include <iostream>
void SetCursorPosition(const int x, const int y)//设置光标位置
{
	COORD position;
	position.X = x * 2;
	position.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
}




void AllenPoint::Print()//输出方块
{
	SetCursorPosition(x, y);
	std::cout << "■";
}

void AllenPoint::PrintCircular()//输出圆形
{
	SetCursorPosition(x, y);
	std::cout << "●";
}

void AllenPoint::Clear()//清除输出
{
	SetCursorPosition(x, y);
	std::cout << "  ";
}

void AllenPoint::ChangePosition(const int x, const int y)//改变坐标
{
	this->x = x;
	this->y = y;
}
