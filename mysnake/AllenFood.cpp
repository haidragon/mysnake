#include "AllenFood.h"
#include "AllenDraw.h"
#include "AllenMap.h"


AllenFood::AllenFood()
{
}


AllenFood::~AllenFood()
{
}
void AllenFood::Create() {
	AllenDraw obj;
	/*int nX, nY;*/
	//int foodx;
	//int foody;
	while (1)
	{
		foodx = rand() % 40;
		foody = rand() % 40;
		if (!g_nMap[foodx][foody])
		{
			obj.WriteChar(MAP_SHAPE_FOOD, foodx, foody, rand() % 0x0F + 0xF0);
			g_nMap[foodx][foody] = MAP_VALUE_FOOD;
			break;
		}
	}
}