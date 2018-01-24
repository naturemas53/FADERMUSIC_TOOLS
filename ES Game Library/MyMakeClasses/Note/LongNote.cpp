#include "LongNote.h"

void LongNote::PlayAreaDraw(float drawareaheight, float drawareawidth, float notehit_xpos, DWORD nowtime){

	Rect userect = RectWH(312, 160, 30, 30);
	SPRITE sp = this->sp_;

	Vector3 startpoint = Vector3_Zero;
	Vector3 goalpoint = Vector3_Zero;
	Vector3 dir;

	float degrees;
	float hypotenuse;

	auto itr = this->points_.begin();
	auto e_itr = this->points_.end();
	e_itr--;

	while (itr != e_itr){

		startpoint = (*itr)->GetPlayAreaPos(drawareaheight, drawareawidth, notehit_xpos, nowtime);
		goalpoint = (*(itr + 1))->GetPlayAreaPos(drawareaheight, drawareawidth, notehit_xpos, nowtime);

		if (goalpoint.y > startpoint.y){

			//ƒm[ƒg‚Ì‘å‚«‚³
			startpoint.x += 30.0f;
			goalpoint.x += 30.0f;

		}

		dir = goalpoint - startpoint;

		degrees = MathHelper_Atan2(dir.y,dir.x);

		dir.x *= dir.x;
		dir.y *= dir.y;

		hypotenuse = dir.x + dir.y;
		hypotenuse = sqrtf(hypotenuse);

		SpriteBatch.Draw(*sp, startpoint, userect, 1.0f, Vector3(0.0f, 0.0f, degrees), Vector3_Zero, Vector2(hypotenuse / 30.0f, 1.0f));


		itr++;
	}

	for (auto point : this->points_) point->PlayAreaDraw(drawareaheight,drawareawidth,notehit_xpos,nowtime);

	Vector3 pos = this->CalcPos(drawareaheight, drawareawidth, notehit_xpos, nowtime);

	
	userect = this->USERECT_;

	DWORD betweentime = this->timing_ - nowtime;
	float timingrate = (float)(1000 - betweentime) / 1000.0f;
	float pal = (timingrate >= 1.0f) ? 0.5f : 1.0f;

	SpriteBatch.Draw(*sp, pos, userect, pal);

	if (this->selectflag_){

		userect = this->MARKUSERECT_;

		SpriteBatch.Draw(*sp, pos, userect, 1.0f);
	}


}