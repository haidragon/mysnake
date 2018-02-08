#include "AllenCustomSence.h"



AllenCustomSence::AllenCustomSence()
{
}


AllenCustomSence::~AllenCustomSence()
{
}
void AllenCustomSence::InitSence() {
	AllenMyDraw allenmydraw;
	allenmydraw.InitSence();
	allenmydraw.MessageLoop();
}