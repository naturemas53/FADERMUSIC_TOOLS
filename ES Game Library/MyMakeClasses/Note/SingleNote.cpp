#include "SingleNote.h"

void SingleNote::NormalDraw(float drawareaheight, float drawareawidth, float notehit_xpos, DWORD nowtime){

	notehit_xpos -= 15.0f; //ノートサイズの半分
	drawareaheight -= 30.0f; //ノートサイズ

	float betweenwidth = drawareawidth - notehit_xpos;
	DWORD betweentime = this->timing_ - nowtime;
	float timingrate = (float)(1000 - betweentime) / 1000.0f;

	float x_pos = drawareawidth - (timingrate * betweenwidth);
	float y_pos = drawareaheight * this->height_;

	Vector3 pos = Vector3_Zero;
	pos.x = x_pos;
	pos.y = y_pos;

	SPRITE sp = this->sp_;
	Rect userect = this->USERECT_;

	SpriteBatch.Draw(*sp,pos,userect,1.0f);
}