#include "AllenDelegate.h"
#include<iostream>
using namespace std;

//�ڴ˴���ʼ��
AllenDelegate* AllenDelegate::instance = new AllenDelegate();
AllenDelegate* AllenDelegate::getInstance() {
	return instance;
}
void AllenDelegate::initmysnake() {
	//���´���ʱ������
	system("cls");
	cout << "�����Ϊ�����޴�Сд��w a s d,��ͣ��Ϊe(�����κμ���ʼ��, �˳���Ϊq��������" << endl;
	cout << "��ѡ���Ѷȣ�" << endl;
	cout << "1:��" << endl;
	cout << "2:�е�" << endl;
	cout << "3:����" << endl;
	cout << "4:�Զ����ͼ(���ұ߰�Ťȷ����" << endl;
	cin >> AllenIntSence;
	//�������̨
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
	////////////////�û�ģʽ����////////////////////
	if (AllenIntSence ==1)
	{
		////////////////��ʼ����////////////////////////
		AllenSence Sencestart;
		Sencestart.Action();
		//--------------��ģʽ----------------------//
		AllenShow allenshow;
		allenshow.gotoxy(82, 5);
		cout << "�Ѷȣ���";
		AllenSimpleSence simplesence;
		simplesence.InitSence();
		
	}
	else if (AllenIntSence == 2)
	{
		////////////////��ʼ����////////////////////////
		AllenSence Sencestart;
		Sencestart.Action();
		//--------------�е�ģʽ----------------------//
		AllenShow allenshow;
		allenshow.gotoxy(82, 5);
		cout << "�Ѷȣ��е�";
		AllenMediumSence mediumsence;
		mediumsence.InitSence();
	}
	else if (AllenIntSence == 3)
	{
		////////////////��ʼ����////////////////////////
		AllenSence Sencestart;
		Sencestart.Action();
		//--------------����ģʽ----------------------//
		AllenShow allenshow;
		allenshow.gotoxy(82, 5);
		cout << "�Ѷȣ�����";
		AllenDifficutSence difficutsence;
		difficutsence.InitSence();
	}
	else if (AllenIntSence == 4)
	{
		//////////////////��ʼ����////////////////////////
		//AllenSence Sencestart;
		//Sencestart.Action();
		//--------------�Զ���ģʽ----------------------//
		//AllenShow allenshow;
		//allenshow.gotoxy(82, 5);
		//cout << "�Ѷȣ�����";
		AllenCustomSence allencustomsence;
		allencustomsence.InitSence();
	}
	else
	{
		////////////////��ʼ����////////////////////////
		AllenSence Sencestart;
		Sencestart.Action();
		//--------------��ģʽ----------------------//
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