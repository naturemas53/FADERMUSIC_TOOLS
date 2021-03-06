#include "SingleNote.h"

void SingleNote::PlayAreaDraw(float drawareaheight, float drawareawidth, float notehit_xpos, DWORD nowtime){

	Vector3 pos = this->CalcPos(drawareaheight,drawareawidth,notehit_xpos,nowtime);

	SPRITE sp = this->sp_;
	Rect userect = this->USERECT_;

	DWORD betweentime = this->timing_ - nowtime;
	float timingrate = (float)(1000 - betweentime) / 1000.0f;
	float pal = (timingrate >= 1.0f) ? 0.5f : 1.0f;

	SpriteBatch.Draw(*sp, pos, userect, pal);

	if (this->selectflag_){

		userect = this->MARKUSERECT_;

		SpriteBatch.Draw(*sp, pos, userect, 1.0f);
	}
}