#ifndef STRATINTERFACE_H
#define STARTINTERFACE_H

#include <deque>
#include <vector>
#include "AllenPoint.h"

class AllenSence
{
public:
	AllenSence() : speed(35) {
		startsnake.emplace_back(AllenPoint(0, 14));//Éß
		startsnake.emplace_back(AllenPoint(1, 14));
		startsnake.emplace_back(AllenPoint(2, 15));
		startsnake.emplace_back(AllenPoint(3, 16));
		startsnake.emplace_back(AllenPoint(4, 17));
		startsnake.emplace_back(AllenPoint(5, 18));
		startsnake.emplace_back(AllenPoint(6, 17));
		startsnake.emplace_back(AllenPoint(7, 16));
		startsnake.emplace_back(AllenPoint(8, 15));
		startsnake.emplace_back(AllenPoint(9, 14));

		textsnake.emplace_back(AllenPoint(-26, 14));//S
		textsnake.emplace_back(AllenPoint(-25, 14));
		textsnake.emplace_back(AllenPoint(-27, 15));
		textsnake.emplace_back(AllenPoint(-26, 16));
		textsnake.emplace_back(AllenPoint(-25, 17));
		textsnake.emplace_back(AllenPoint(-27, 18));
		textsnake.emplace_back(AllenPoint(-26, 18));

		textsnake.emplace_back(AllenPoint(-23, 14));//N
		textsnake.emplace_back(AllenPoint(-23, 15));
		textsnake.emplace_back(AllenPoint(-23, 16));
		textsnake.emplace_back(AllenPoint(-23, 17));
		textsnake.emplace_back(AllenPoint(-23, 18));
		textsnake.emplace_back(AllenPoint(-22, 15));
		textsnake.emplace_back(AllenPoint(-21, 16));
		textsnake.emplace_back(AllenPoint(-20, 17));
		textsnake.emplace_back(AllenPoint(-19, 14));
		textsnake.emplace_back(AllenPoint(-19, 15));
		textsnake.emplace_back(AllenPoint(-19, 16));
		textsnake.emplace_back(AllenPoint(-19, 17));
		textsnake.emplace_back(AllenPoint(-19, 18));

		textsnake.emplace_back(AllenPoint(-17, 18));//A
		textsnake.emplace_back(AllenPoint(-16, 17));
		textsnake.emplace_back(AllenPoint(-15, 16));
		textsnake.emplace_back(AllenPoint(-14, 15));
		textsnake.emplace_back(AllenPoint(-14, 16));
		textsnake.emplace_back(AllenPoint(-13, 14));
		textsnake.emplace_back(AllenPoint(-13, 16));
		textsnake.emplace_back(AllenPoint(-12, 15));
		textsnake.emplace_back(AllenPoint(-12, 16));
		textsnake.emplace_back(AllenPoint(-11, 16));
		textsnake.emplace_back(AllenPoint(-10, 17));
		textsnake.emplace_back(AllenPoint(-9, 18));

		textsnake.emplace_back(AllenPoint(-7, 14));//K
		textsnake.emplace_back(AllenPoint(-7, 15));
		textsnake.emplace_back(AllenPoint(-7, 16));
		textsnake.emplace_back(AllenPoint(-7, 17));
		textsnake.emplace_back(AllenPoint(-7, 18));
		textsnake.emplace_back(AllenPoint(-6, 16));
		textsnake.emplace_back(AllenPoint(-5, 15));
		textsnake.emplace_back(AllenPoint(-5, 17));
		textsnake.emplace_back(AllenPoint(-4, 14));
		textsnake.emplace_back(AllenPoint(-4, 18));

		textsnake.emplace_back(AllenPoint(-2, 14));//E
		textsnake.emplace_back(AllenPoint(-2, 15));
		textsnake.emplace_back(AllenPoint(-2, 16));
		textsnake.emplace_back(AllenPoint(-2, 17));
		textsnake.emplace_back(AllenPoint(-2, 18));
		textsnake.emplace_back(AllenPoint(-1, 14));
		textsnake.emplace_back(AllenPoint(-1, 16));
		textsnake.emplace_back(AllenPoint(-1, 18));
		textsnake.emplace_back(AllenPoint(0, 14));
		textsnake.emplace_back(AllenPoint(0, 16));
		textsnake.emplace_back(AllenPoint(0, 18));
	}
	void PrintFirst();
	void PrintSecond();
	void PrintThird();
	void PrintText();
	void ClearText();
	void Action();
private:
	std::deque<AllenPoint> startsnake;//开始动画中的蛇
	std::vector<AllenPoint> textsnake;//开始动画中的文字
	int speed;//动画的速度
};
#endif // STRATINTERFACE_H
