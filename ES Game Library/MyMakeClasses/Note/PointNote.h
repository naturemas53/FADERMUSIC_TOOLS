#pragma once
#include "AbstructNote.h"

class PointNote : public AbstructNote{

public:

	PointNote(AbstructNote* note) :
		AbstructNote(RectWH(252, 160, 30, 30), POINTNOTE){
	
		this->ValueCopy(note);
	
	}

	virtual ~PointNote() = default;
	
	virtual void PlayAreaDraw(float drawareaheight, float drawareawidth, float notehit_xpos, DWORD nowtime);

private:

};