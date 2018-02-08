#include "AllenMediumSence.h"
using namespace std;
AllenMediumSence::AllenMediumSence()
{
}
AllenMediumSence::~AllenMediumSence()
{
}
void AllenMediumSence::InitSence() {
	srand(unsigned int(time(0)));
	// 先设置窗口大小
	AllenMap obj;
	obj.SetWindowInfo("Snake", 100, 41);
	// 初始化地图
	obj.InitMap();
	obj.DrawMap();
	// 初始化蛇
	Nnum = 1;
	Nnum2 = 1;
	AllenSnake objSnake;
	//位置随机
	int initsnakeX;
	int initsnakeyY;
	while (true)
	{
		initsnakeX = rand() % MAP_WIDTH;
		initsnakeyY = rand() % MAP_HEIGHT;
		if (g_nMap[initsnakeX][initsnakeyY] == 0) {
			break;
		}

	}
	objSnake.InitSnake(initsnakeX, initsnakeyY, SNAKE_DIR_UP);
	//生成食物
	AllenFood objFood;
	objFood.Create();
	char ch = _getch();
	if (ch == 'w' || ch == 'W' || ch == 'a' || ch == 'A' || ch == 's' || ch == 'S' || ch == 'd' || ch == 'D') {
		// 设置蛇的移动时间间隔
		clock_t tBegin = clock(), tEnd = 0;
		while (true) {

			if (_kbhit())
			{
				char ch = _getch();
				objSnake.ChangeDir(ch);
				////暂停
				//if (ch == 'e' || ch == 'E') {
				//	cin.get();

				//}

			}
			tEnd = clock();
			if (tEnd - tBegin > 100)
			{
				tBegin = tEnd;
				objSnake.SnakeMove();
				if (objSnake.m_bDie || Nnum == 0) {
					AllenMessageBoxA mybox;
					mybox.mybox();
					//MessageBoxA(0, "GG！", "菜鸟！", MB_OK);
					break;
				}
			}
		}
	}
}