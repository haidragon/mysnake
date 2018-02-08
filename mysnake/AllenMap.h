#pragma once
#define MAP_WIDTH	40
#define MAP_HEIGHT	40
#define MAP_VALUE_WALL 1
#define MAP_VALUE_SNAKE 2
#define MAP_VALUE_FOOD 3
#define MAP_VALUE_WALL2 6

#define MAP_SHAPE_FOOD "☆"
#define MAP_SHAPE_WALL "■"
#define MAP_SHAPE_WALL2 "■"

class AllenMap
{
public:
	AllenMap();
	~AllenMap();
	//设置标题，宽高
	bool SetWindowInfo(char* pTitle, int nWid, int nHeight);
	//初始化地图
	bool InitMap();
	//画地图
	bool DrawMap();
	
};
//二维数组保存地图坐标
extern int g_nMap[MAP_HEIGHT][MAP_WIDTH];
//全局变量设置难度
extern int AllenIntSence;

extern bool AllenMyDrawMap;