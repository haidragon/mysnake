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
	// �����ô��ڴ�С
	AllenMap obj;
	obj.SetWindowInfo("Snake", 100, 41);
	// ��ʼ����ͼ
	obj.InitMap();
	obj.DrawMap();
	// ��ʼ����
	Nnum = 1;
	Nnum2 = 1;
	AllenSnake objSnake;
	//λ�����
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
	//����ʳ��
	AllenFood objFood;
	objFood.Create();
	char ch = _getch();
	if (ch == 'w' || ch == 'W' || ch == 'a' || ch == 'A' || ch == 's' || ch == 'S' || ch == 'd' || ch == 'D') {
		// �����ߵ��ƶ�ʱ����
		clock_t tBegin = clock(), tEnd = 0;
		while (true) {

			if (_kbhit())
			{
				char ch = _getch();
				objSnake.ChangeDir(ch);
				////��ͣ
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
					//MessageBoxA(0, "GG��", "����", MB_OK);
					break;
				}
			}
		}
	}
}