#include "AllenSave.h"
#include "AllenMap.h"
#include<fstream>
using namespace std;
AllenSave::AllenSave()
{
}


AllenSave::~AllenSave()
{
}
void AllenSave::save() {
	fstream outfile("ditu.txt", ios::app);
	for (int i = 0; i < 40; i++) {
		for (int j = 0; j < 40; j++) {
			outfile << ditu[i][j];
		}
	}
}
void AllenSave::read() {

}
//g_nMap[MAP_HEIGHT][MAP_WIDTH];