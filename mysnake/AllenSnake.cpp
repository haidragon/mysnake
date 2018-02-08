#include "AllenSnake.h"
#include "AllenMap.h"
#include "AllenFood.h"
#include "AllenDraw.h"
#include<iostream>
#include "AllenShow.h"
#include <conio.h>
using namespace std;
AllenSnake::AllenSnake()
{
	m_bDie = false;
	//vector<SNAKENODE> m_vecSnake;

}


AllenSnake::~AllenSnake()
{
}
void AllenSnake::InitSnake(int nX, int nY, int nDir) {
	// ������ߵ�������
	SNAKENODE fir = { nX,nY };
	m_vecSnake.push_back(fir);
	m_nDir = nDir;
	// ������
	AllenDraw obj;
	obj.WriteChar(SNAKE_SHAPE, nX, nY, rand() % 0x0F + 0xF0);
	g_nMap[nY][nX] = MAP_VALUE_SNAKE;
}

bool AllenSnake::SnakeMove() {
	// �ܲ��ܶ���
	if (!SnakeCanMove())
	{
		// �߹���
		return false;
	}
	
	AllenDraw obj;
	// �Ȱ�֮ǰ�Ĳ���
	int nSize = m_vecSnake.size();
	for (int i = 0; i<nSize; i++)
	{
		obj.WriteChar(SNAKE_CLEAR,
			m_vecSnake[i].nPosX,
			m_vecSnake[i].nPosY, 0xFF);
		g_nMap[m_vecSnake[i].nPosY][m_vecSnake[i].nPosX] = 0;
	}
	// ���ƶ�
	// �ƶ��ߵ�����
	for (int i = nSize-1; i>=1; i--)
	{
		m_vecSnake[i].nPosX = m_vecSnake[i-1].nPosX;
		m_vecSnake[i].nPosY = m_vecSnake[i - 1].nPosY;
	}
	//m_vecSnake[0].nPosX = m_vecSnake[nSize - 1].nPosX;
	//m_vecSnake[0].nPosY = m_vecSnake[nSize - 1].nPosY;

	//g_nMap[m_vecSnake[nSize - 1].nPosY][m_vecSnake[nSize - 1].nPosX] = 0;

	// ����ͷ
	switch (m_nDir) {
	case SNAKE_DIR_UP:
		m_vecSnake[0].nPosY--;
		break;
	case SNAKE_DIR_DW:
		m_vecSnake[0].nPosY++;
		break;
	case SNAKE_DIR_LF:
		m_vecSnake[0].nPosX--;
		break;
	case SNAKE_DIR_RH:
		m_vecSnake[0].nPosX++;
		break;
	}
	
	//ÿ�ƶ�һ���ж���ͷ�Ƿ���ʳ��λ��
	if (m_vecSnake[0].nPosX == foodx&&m_vecSnake[0].nPosY == foody) {
		Eat();
	}

	//if (g_nMap[m_vecSnake[0].nPosX][m_vecSnake[0].nPosY]== MAP_VALUE_WALL2) {
	//	Nnum--;
	//}
	// ����ͷ
	//int m_nDir;
//#define SNAKE_SHAPESHENUP "��"
//#define SNAKE_SHAPESHENDW "��"
//#define SNAKE_SHAPESHENL "��"
//#define SNAKE_SHAPESHENR "��"
//#define SNAKE_DIR_UP 0
//#define SNAKE_DIR_DW 2
//#define SNAKE_DIR_LF 1
//#define SNAKE_DIR_RH 3
	//��ͷ
	if (m_nDir == SNAKE_DIR_UP) {
		obj.WriteChar(SNAKE_SHAPESHENUP,
			m_vecSnake[0].nPosX,
			m_vecSnake[0].nPosY, rand() % 0x0F + 0xF0);
		g_nMap[m_vecSnake[0].nPosY][m_vecSnake[0].nPosX] = MAP_VALUE_SNAKE;
	}
	else if (m_nDir == SNAKE_DIR_DW) {
		obj.WriteChar(SNAKE_SHAPESHENDW,
			m_vecSnake[0].nPosX,
			m_vecSnake[0].nPosY, rand() % 0x0F + 0xF0);
		g_nMap[m_vecSnake[0].nPosY][m_vecSnake[0].nPosX] = MAP_VALUE_SNAKE;
	}
	else if (m_nDir == SNAKE_DIR_LF) {
		obj.WriteChar(SNAKE_SHAPESHENL,
			m_vecSnake[0].nPosX,
			m_vecSnake[0].nPosY, rand() % 0x0F + 0xF0);
		g_nMap[m_vecSnake[0].nPosY][m_vecSnake[0].nPosX] = MAP_VALUE_SNAKE;
	}
	else
	{
		obj.WriteChar(SNAKE_SHAPESHENR,
			m_vecSnake[0].nPosX,
			m_vecSnake[0].nPosY, rand() % 0x0F + 0xF0);
		g_nMap[m_vecSnake[0].nPosY][m_vecSnake[0].nPosX] = MAP_VALUE_SNAKE;
	}
	//�ߵĵڶ���
	if (nSize >2) {
		obj.WriteChar(SNAKE_SHAPE,
			m_vecSnake[1].nPosX,
			m_vecSnake[1].nPosY, rand() % 0x0F + 0xF0);
		g_nMap[m_vecSnake[1].nPosY][m_vecSnake[1].nPosX] = MAP_VALUE_SNAKE;
	}
	// ������
	for (int i = 2; i < nSize-1; i++) {
		if (i % 2 == 0) {
			obj.WriteChar(SNAKE_SHAPESHEN,
				m_vecSnake[i].nPosX,
				m_vecSnake[i].nPosY, rand() % 0x0F + 0xF0);
			g_nMap[m_vecSnake[i].nPosY][m_vecSnake[i].nPosX] = MAP_VALUE_SNAKE;
		}
		else
		{
			obj.WriteChar(SNAKE_SHAPESHEN2,
				m_vecSnake[i].nPosX,
				m_vecSnake[i].nPosY, rand() % 0x0F + 0xF0);
			g_nMap[m_vecSnake[i].nPosY][m_vecSnake[i].nPosX] = MAP_VALUE_SNAKE;
		}
	}
	// ����β
	if (nSize>1) {
		obj.WriteChar(SNAKE_SHAPESHEN3,
			m_vecSnake[nSize - 1].nPosX,
			m_vecSnake[nSize - 1].nPosY, rand() % 0x0F + 0xF0);
		g_nMap[m_vecSnake[nSize - 1].nPosY][m_vecSnake[nSize - 1].nPosX] = MAP_VALUE_SNAKE;

	}
//ÿ�ƶ�һ��ˢ�·���
	AllenShow allenshow;
	allenshow.gotoxy(82, 10);
	cout << "��ǰ������" << Nnum2*100;
	allenshow.gotoxy(82, 15);
	cout << "��ǰ����ֵ��" << Nnum;
	return true;
}


bool AllenSnake::ChangeDir(char cDir) {
	int nNewDir = -1;
	switch (cDir) {
	case 'W':
	case 'w':
		nNewDir = SNAKE_DIR_UP;
		break;
	case 's':
	case 'S':
		nNewDir = SNAKE_DIR_DW;
		break;
	case 'a':
	case 'A':
		nNewDir = SNAKE_DIR_LF;
		break;
	case 'd':
	case 'D':
		nNewDir = SNAKE_DIR_RH;
		break;
	case 'q':
	case 'Q':
		exit(0);
		break;
	case 'e':
	case 'E':
		_getch();
		break;
	default:
		break;
	}

	if (nNewDir == -1)
	{
		return false;
	}
	// �����ԭ���ķ����෴���Ͳ�����
	if (abs(nNewDir - m_nDir) == 2)
	{
		return false;
	}
	if (m_nDir == nNewDir)
	{
		SnakeMove();
		return true;
	}
	// ���������ͬ���ͼ���
	m_nDir = nNewDir;
	return true;
}

bool AllenSnake::SnakeCanMove() {
	SNAKENODE temp = m_vecSnake[0];
	// �ж��¸������Ƿ���Ч
	switch (m_nDir) {
	case SNAKE_DIR_UP:
		temp.nPosY--;
		break;
	case SNAKE_DIR_DW:
		temp.nPosY++;
		break;
	case SNAKE_DIR_LF:
		temp.nPosX--;
		break;
	case SNAKE_DIR_RH:
		temp.nPosX++;
		break;
	}
	// ���ܶ������
	switch (g_nMap[temp.nPosY][temp.nPosX]) {
	case MAP_VALUE_SNAKE:
	case MAP_VALUE_WALL:
		m_bDie = true;
		return false;
	case MAP_VALUE_WALL2:
		Nnum--;
		//g_nMap[m_vecSnake[m_vecSnake.size()-1].nPosX][m_vecSnake[m_vecSnake.size()-1].nPosY] = 0;
		//m_vecSnake.pop_back();
		// ������
/*		AllenDraw obj;
		obj.WriteChar(MAP_SHAPE_WALL2, m_vecSnake.size() - 1, m_vecSnake.size() - 1, rand() % 0x0F + 0xF0);
	*/	return true;
	case MAP_VALUE_FOOD:
		//Eat();
		return true;
	default:
		break;
	}
	return true;
}

void AllenSnake::Eat() {
	PlaySoundA("eat.wav", NULL, SND_ASYNC | SND_NODEFAULT);
	//����һ������
	SNAKENODE snake1;
	Nnum++;
	Nnum2++;
	//λ��Ϊʳ���λ��
	g_nMap[foodx][foody] =0;
	snake1.nPosX = foodx;
	snake1.nPosY = foody;
	g_nMap[foodx][foody] = 0; 
	m_vecSnake.push_back(snake1);
	//����һ��ʳ��
	AllenFood objfood;
	objfood.Create();
}
