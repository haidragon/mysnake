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
	//设置窗口标题
	SetConsoleTitleA(pTitle);
	// 设置窗口大小
	// 因为屏幕大小不能比缓冲区大，所以先把缓冲区大小设置为足够大
	// 先获取当前屏幕的最大值
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD cd = GetLargestConsoleWindowSize(hOut);
	// 设置缓冲区最大值
	if (!SetConsoleScreenBufferSize(hOut, cd)) {
		printf("设置窗口缓冲区大小失败1！\n");
		return false;
	}
	// 按要求设置窗口大小
	SMALL_RECT sr = { 0,0,nWid - 1,nHeight - 1 };
	if (!SetConsoleWindowInfo(hOut, 1, &sr)) {
		printf("设置窗口大小失败！\n");
		return false;
	}
	// 重新设置缓冲区大小
	cd.X = nWid;
	cd.Y = nHeight;
	if (!SetConsoleScreenBufferSize(hOut, cd)) {
		printf("设置窗口缓冲区大小失败2！\n");
		return false;
	}
	return true;
}
bool AllenMap::InitMap() {

	if (!AllenMyDrawMap) {
		//当下次来时先清理
		for (int i = 0; i < MAP_HEIGHT - 1; i++) {
			for (int j = 0; j < MAP_WIDTH - 1; j++) {
				g_nMap[i][j] = 0;
			}
		}
		AllenMyDrawMap = false;
	}
	
	//设置边框
	for (int i = 0; i < MAP_HEIGHT; i++) {
		for (int j = 0; j <MAP_WIDTH; j++) {
			if (i == 0 || i == MAP_HEIGHT - 1 ||
				j == 0 || j == MAP_WIDTH - 1) {
				g_nMap[i][j] = MAP_VALUE_WALL;
			}
		}
	}
	if (AllenIntSence == 2) {
		//随机添加障碍物
		int nX, nY;
		for (int i = 0; i<10; i++)
		{
			nX = rand() % 40;
			nY = rand() % 40;
			g_nMap[nY][nX] = MAP_VALUE_WALL2;
		}
	}
	if (AllenIntSence == 3) {
		//随机添加障碍物
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

