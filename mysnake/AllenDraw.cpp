#include "AllenDraw.h"
AllenDraw::AllenDraw()
{
}
AllenDraw::~AllenDraw()
{
}
void AllenDraw::WriteChar(char* psz, int nPosX, int nPosY, WORD wAttr) {
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