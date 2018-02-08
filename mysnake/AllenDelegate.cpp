#include "AllenDelegate.h"
#include<iostream>
using namespace std;

//在此处初始化
AllenDelegate* AllenDelegate::instance = new AllenDelegate();
AllenDelegate* AllenDelegate::getInstance() {
	return instance;
}
void AllenDelegate::initmysnake() {
	//当下次来时先清理
	system("cls");
	cout << "方向键为（不限大小写）w a s d,暂停键为e(按下任何键开始）, 退出键为q！！！！" << endl;
	cout << "请选择难度：" << endl;
	cout << "1:简单" << endl;
	cout << "2:中等" << endl;
	cout << "3:困难" << endl;
	cout << "4:自定义地图(按右边按扭确定）" << endl;
	cin >> AllenIntSence;
	//清理控制台
	system("cls");
	//if (rand() % 3 == 0) {
	//	PlaySoundA("one.wav", NULL, SND_ASYNC | SND_NODEFAULT);
	//}
	//else if(rand() % 3 == 1)
	//{
	//	PlaySoundA("twe.wav", NULL, SND_ASYNC | SND_NODEFAULT);
	//}
	//else
	//{
	//	PlaySoundA("three.wav", NULL, SND_ASYNC | SND_NODEFAULT);

	//}
	////////////////用户模式场景////////////////////
	if (AllenIntSence ==1)
	{
		////////////////开始场景////////////////////////
		AllenSence Sencestart;
		Sencestart.Action();
		//--------------简单模式----------------------//
		AllenShow allenshow;
		allenshow.gotoxy(82, 5);
		cout << "难度：简单";
		AllenSimpleSence simplesence;
		simplesence.InitSence();
		
	}
	else if (AllenIntSence == 2)
	{
		////////////////开始场景////////////////////////
		AllenSence Sencestart;
		Sencestart.Action();
		//--------------中等模式----------------------//
		AllenShow allenshow;
		allenshow.gotoxy(82, 5);
		cout << "难度：中等";
		AllenMediumSence mediumsence;
		mediumsence.InitSence();
	}
	else if (AllenIntSence == 3)
	{
		////////////////开始场景////////////////////////
		AllenSence Sencestart;
		Sencestart.Action();
		//--------------困难模式----------------------//
		AllenShow allenshow;
		allenshow.gotoxy(82, 5);
		cout << "难度：困难";
		AllenDifficutSence difficutsence;
		difficutsence.InitSence();
	}
	else if (AllenIntSence == 4)
	{
		//////////////////开始场景////////////////////////
		//AllenSence Sencestart;
		//Sencestart.Action();
		//--------------自定义模式----------------------//
		//AllenShow allenshow;
		//allenshow.gotoxy(82, 5);
		//cout << "难度：困难";
		AllenCustomSence allencustomsence;
		allencustomsence.InitSence();
	}
	else
	{
		////////////////开始场景////////////////////////
		AllenSence Sencestart;
		Sencestart.Action();
		//--------------简单模式----------------------//
		AllenSimpleSence simplesence;
		simplesence.InitSence();
	}
}
AllenDelegate::~AllenDelegate()
{
}

AllenDelegate::AllenDelegate() {

}
AllenDelegate::AllenDelegate(const AllenDelegate&) {

}
AllenDelegate& AllenDelegate::operator=(const AllenDelegate&) {
	return *instance;
}