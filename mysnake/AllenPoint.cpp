#include "AllenPoint.h"
//#include "tools.h"
#include <windows.h>
#include <stdio.h>
#include <iostream>
void SetCursorPosition(const int x, const int y)//���ù��λ��
{
	COORD position;
	position.X = x * 2;
	position.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
}




void AllenPoint::Print()//�������
{
	SetCursorPosition(x, y);
	std::cout << "��";
}

void AllenPoint::PrintCircular()//���Բ��
{
	SetCursorPosition(x, y);
	std::cout << "��";
}

void AllenPoint::Clear()//������
{
	SetCursorPosition(x, y);
	std::cout << "  ";
}

void AllenPoint::ChangePosition(const int x, const int y)//�ı�����
{
	this->x = x;
	this->y = y;
}
