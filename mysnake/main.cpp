#include "AllenDelegate.h"

//ʳ������
 int foodx=0;
 int foody=0;
 //ģʽ
 int AllenIntSence = 0;
 //����
 int Nnum = 0;
 int Nnum2 = 1;
int main()
{
	//////////////////ģ�ⰴ��shit��////////////////
	keybd_event(VK_SHIFT, 0, 0, 0);
	keybd_event(VK_SHIFT, 0, KEYEVENTF_KEYUP, 0);
	///////////////ͨ��������������/////////////////
	AllenDelegate* mysnake= AllenDelegate::getInstance();
	mysnake->initmysnake();
	//cin.get();
	return 0;
}