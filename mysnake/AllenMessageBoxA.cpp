#include "AllenMessageBoxA.h"
#include "AllenDelegate.h"
#include "AllenMap.h"


AllenMessageBoxA::AllenMessageBoxA()
{
}


AllenMessageBoxA::~AllenMessageBoxA()
{
}
void AllenMessageBoxA::mybox()
{
	//PlaySoundA("die.wav", NULL, SND_ASYNC | SND_NODEFAULT);
	g_nMap[MAP_HEIGHT][MAP_WIDTH] = 0;
	MessageBoxA(0, "GG£¡", "²ËÄñ£¡", MB_OK);
	Sleep(1000);
	
	AllenDelegate* mysnake = AllenDelegate::getInstance();
	mysnake->initmysnake();


}