#include "AbstructNote.h"
#include "../SpriteSingleton.h"

SPRITE AbstructNote::sp_ = nullptr;

AbstructNote::AbstructNote(RectWH userect, NoteType type) :
USERECT_(userect),
TYPE_(type),
SIZE_(Vector2(30.0f, 30.0f)){

	if (this->sp_ == nullptr){

		this->sp_ = StaticSprite.GetSprite();

	}

}

void AbstructNote::SimpleDraw(float drawareaheight, float drawareawidth, float notehit_xpos, DWORD nowtime){

	notehit_xpos -= 15.0f; //(�m�[�g�T�C�Y�̔���)
	//drawareawidth += 30.0f;//30.0f�̓m�[�g�̑傫��

	float betweenwidth = drawareawidth - notehit_xpos;
	DWORD betweentime = this->timing_ - nowtime;
	float timingrate = (float)(1000 - betweentime) / 1000.0f;

	float x_pos = drawareawidth - (timingrate * betweenwidth);
	float y_pos = (drawareaheight - 30.0f) / 2.0f; 

	SPRITE sp = this->sp_;
	Rect userect = this->USERECT_;

	Vector3 pos = Vector3_Zero;
	pos.x = x_pos;
	pos.y = y_pos;

	SpriteBatch.Draw(*sp,pos,userect,1.0f);

}