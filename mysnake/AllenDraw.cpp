#include "AllenDraw.h"
AllenDraw::AllenDraw()
{
}
AllenDraw::~AllenDraw()
{
}
void AllenDraw::WriteChar(char* psz, int nPosX, int nPosY, WORD wAttr) {
	// 设置光标位置
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos = { nPosX * 2,nPosY };
	SetConsoleCursorPosition(hOut, pos);
	// 隐藏光标
	CONSOLE_CURSOR_INFO ci;
	ci.bVisible = FALSE;
	ci.dwSize = 1;
	SetConsoleCursorInfo(hOut, &ci);
	// 设置打印符号的前景色背景色
	SetConsoleTextAttribute(hOut, wAttr);
	// 输出你想输出的
	printf("%s", psz);
}