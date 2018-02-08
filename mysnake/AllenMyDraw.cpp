#include "AllenMyDraw.h"
#include <windows.h>
#include <conio.h> 
#include<cstdio>
#include<iostream>
using namespace std;
void AllenMyDraw::InitSence() {
	// �����ô��ڴ�С
	AllenMap obj;
	obj.SetWindowInfo("�Զ���", 100, 41);
	//������
	AllenMyDrawMap = true;
	for (int i = 0; i < MAP_HEIGHT - 1; i++) {
		for (int j = 0; j < MAP_WIDTH - 1; j++) {
			g_nMap[i][j] = 0;
		}
	}
	AllenMap allenmap;
	allenmap.DrawMap();
	/*WriteChar("ok", 100, 5, 0x33);*/
	AllenShow allenshow;
	allenshow.gotoxy(82, 10);
	cout << "      ";
}
void AllenMyDraw::start() {
	//���´���ʱ������
	//system("cls");
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
			if (tEnd - tBegin > 200)
			{
				tBegin = tEnd;
				objSnake.SnakeMove();
				if (objSnake.m_bDie||Nnum==0) {
					AllenMessageBoxA mybox;
					mybox.mybox();
					//MessageBoxA(0, "GG��", "����", MB_OK);
					break;
				}
			}
		}
	}
}
void AllenMyDraw::MouseEventProc(MOUSE_EVENT_RECORD mer) {
	
	//�����������ǽ
	if (mer.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED) {
		int x = mer.dwMousePosition.X/2;
		int y =  mer.dwMousePosition.Y;
		g_nMap[y][x] = MAP_VALUE_WALL2;


		OutputPos(mer.dwMousePosition.X, mer.dwMousePosition.Y);

		if ((x >40&&x<45) && y == 10) {
			start();
         }
		if (x <40 && y < 40) {
			WriteChar(MAP_SHAPE_WALL2, (mer.dwMousePosition.X) / 2, mer.dwMousePosition.Y, 0x66);
		}
		//g_nMap[(mer.dwMousePosition.X) / 2][mer.dwMousePosition.Y] = MAP_VALUE_WALL;
		//���������ͬʱ�ƶ���껭ǽ
		if (mer.dwEventFlags == MOUSE_MOVED) {
			OutputPos(mer.dwMousePosition.X, mer.dwMousePosition.Y);
			if (mer.dwMousePosition.X < 80 || mer.dwMousePosition.Y < 40) {
				WriteChar(MAP_SHAPE_WALL2, (mer.dwMousePosition.X) / 2, mer.dwMousePosition.Y, 0x66);

			}
			//g_nMap[(mer.dwMousePosition.X) / 2][mer.dwMousePosition.Y] = MAP_VALUE_WALL;
		}
	}
	else if (mer.dwButtonState == RIGHTMOST_BUTTON_PRESSED) {
		WriteChar("�ҵ���", (mer.dwMousePosition.X) / 2, mer.dwMousePosition.Y, 0x66);
	}

}

//�����������
void AllenMyDraw::OutputPos(int nX, int nY) {
	char szBuf[100] = { 10 };
	sprintf_s(szBuf, sizeof(szBuf), "x=%2d,y=%2d   ", nX, nY);
	SetConsoleTitleA(szBuf);
	WriteChar(szBuf, 0, 0, 0x50);
}
int AllenMyDraw::MessageLoop()
{
	//��ȡһ�����
	HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
	//����һ������ṹ��
	INPUT_RECORD stcRcord = { 0 };

	DWORD dwRead;
	//���ÿ���̨ģʽ�������
	SetConsoleMode(hStdin, ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT);
	while (1)
	{
		ReadConsoleInput(hStdin, &stcRcord, 1, &dwRead);
		if (stcRcord.EventType == KEY_EVENT) {

		}
		else if (stcRcord.EventType == MOUSE_EVENT) {
			MouseEventProc(stcRcord.Event.MouseEvent);
		}
	}


}
void AllenMyDraw::WriteChar(char* psz, int nPosX, int nPosY, WORD wAttr) {
	// ���ù��λ��
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos = { nPosX * 2,nPosY };
	SetConsoleCursorPosition(hOut, pos);
	// ���ع��
	CONSOLE_CURSOR_INFO ci;
	ci.bVisible = FALSE;
	ci.dwSize = 1;
	SetConsoleCursorInfo(hOut, &ci);
	// ���ô�ӡ���ŵ�ǰ��ɫ����ɫ
	SetConsoleTextAttribute(hOut, wAttr);
	// ������������
	printf("%s", psz);
}

AllenMyDraw::AllenMyDraw()
{
}
AllenMyDraw::~AllenMyDraw()
{
}