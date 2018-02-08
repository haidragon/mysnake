#include "AllenMap.h"
#include <windows.h>
#include<stdio.h>
#include "AllenDraw.h"
#include "AllenSave.h"
int g_nMap[MAP_HEIGHT][MAP_WIDTH] = {};
bool AllenMyDrawMap = false;
AllenMap::AllenMap()
{
}
AllenMap::~AllenMap()
{
}
bool AllenMap::SetWindowInfo(char* pTitle, int nWid, int nHeight) {
	//���ô��ڱ���
	SetConsoleTitleA(pTitle);
	// ���ô��ڴ�С
	// ��Ϊ��Ļ��С���ܱȻ������������Ȱѻ�������С����Ϊ�㹻��
	// �Ȼ�ȡ��ǰ��Ļ�����ֵ
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD cd = GetLargestConsoleWindowSize(hOut);
	// ���û��������ֵ
	if (!SetConsoleScreenBufferSize(hOut, cd)) {
		printf("���ô��ڻ�������Сʧ��1��\n");
		return false;
	}
	// ��Ҫ�����ô��ڴ�С
	SMALL_RECT sr = { 0,0,nWid - 1,nHeight - 1 };
	if (!SetConsoleWindowInfo(hOut, 1, &sr)) {
		printf("���ô��ڴ�Сʧ�ܣ�\n");
		return false;
	}
	// �������û�������С
	cd.X = nWid;
	cd.Y = nHeight;
	if (!SetConsoleScreenBufferSize(hOut, cd)) {
		printf("���ô��ڻ�������Сʧ��2��\n");
		return false;
	}
	return true;
}
bool AllenMap::InitMap() {

	if (!AllenMyDrawMap) {
		//���´���ʱ������
		for (int i = 0; i < MAP_HEIGHT - 1; i++) {
			for (int j = 0; j < MAP_WIDTH - 1; j++) {
				g_nMap[i][j] = 0;
			}
		}
		AllenMyDrawMap = false;
	}
	
	//���ñ߿�
	for (int i = 0; i < MAP_HEIGHT; i++) {
		for (int j = 0; j <MAP_WIDTH; j++) {
			if (i == 0 || i == MAP_HEIGHT - 1 ||
				j == 0 || j == MAP_WIDTH - 1) {
				g_nMap[i][j] = MAP_VALUE_WALL;
			}
		}
	}
	if (AllenIntSence == 2) {
		//�������ϰ���
		int nX, nY;
		for (int i = 0; i<10; i++)
		{
			nX = rand() % 40;
			nY = rand() % 40;
			g_nMap[nY][nX] = MAP_VALUE_WALL2;
		}
	}
	if (AllenIntSence == 3) {
		//�������ϰ���
		int nX, nY;
		for (int i = 0; i<20; i++)
		{
			nX = rand() % 40;
			nY = rand() % 40;
			g_nMap[nY][nX] = MAP_VALUE_WALL2;
		}
	}
	return true;
}

bool AllenMap::DrawMap() {
	AllenDraw obj;
	for (int i = 0; i < MAP_HEIGHT; i++) {
		for (int j = 0; j < MAP_WIDTH; j++) {
			if (g_nMap[i][j] == MAP_VALUE_WALL) {
				//rand() % 0x0F + 0xF0
				obj.WriteChar(MAP_SHAPE_WALL, j, i, 0x66);
			}
			else if (g_nMap[i][j] == MAP_VALUE_WALL2) {
				obj.WriteChar(MAP_SHAPE_WALL2, j, i, 0x66);
			}
			else {
				obj.WriteChar("  ", j, i, 0xFF);
			}
		}
	}
	return true;
}

