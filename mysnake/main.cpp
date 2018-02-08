#include "AllenDelegate.h"

//食物坐标
 int foodx=0;
 int foody=0;
 //模式
 int AllenIntSence = 0;
 //分数
 int Nnum = 0;
 int Nnum2 = 1;
int main()
{
	//////////////////模拟按下shit键////////////////
	keybd_event(VK_SHIFT, 0, 0, 0);
	keybd_event(VK_SHIFT, 0, KEYEVENTF_KEYUP, 0);
	///////////////通过代理启动场景/////////////////
	AllenDelegate* mysnake= AllenDelegate::getInstance();
	mysnake->initmysnake();
	//cin.get();
	return 0;
}