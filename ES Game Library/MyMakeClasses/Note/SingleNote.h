#pragma once
#include "AbstructNote.h"

class SingleNote : public AbstructNote{

public:

	SingleNote() :
		AbstructNote(RectWH(192, 160, 30, 30), SINGLENOTE){};
	virtual ~SingleNote() = default;

	virtual void PlayAreaDraw(float drawareaheight, float drawareawidth, float notehit_xpos, DWORD nowtime);

private:

};