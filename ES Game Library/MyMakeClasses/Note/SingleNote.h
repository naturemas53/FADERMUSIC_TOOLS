#pragma once
#include "AbstructNote.h"

class SingleNote : public AbstructNote{

public:

	SingleNote() :
		AbstructNote(RectWH(192, 160, 30, 30), SINGLENOTE){};
	virtual ~SingleNote() = default;

	virtual void NormalDraw(float drawareaheight, float drawareawidth, float notehit_xpos, DWORD nowtime);

	virtual bool ClickCheck(
		Vector2 mouse_pos, 
		Vector3 collectionpos,
		float drawareaheight, 
		float drawareawidth,
		float notehit_xpos,
		DWORD nowtime){ return false; };

	virtual AbstructNote* GetMe(){ return this; }

private:

};