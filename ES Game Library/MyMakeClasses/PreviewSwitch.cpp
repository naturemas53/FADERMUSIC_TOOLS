#include "PreviewSwitch.h"

void PreviewSwitch::Draw(){

	SPRITE sp = this->SPRITES_;
	Vector3 pos = this->POS_;
	Rect userect = this->USERECT_;
	Vector2 size = this->SIZE_;

	if (this->nowpush_){
		userect.top += (LONG)size.y;
		userect.bottom += (LONG)size.y;
	}

	SpriteBatch.Draw(*sp, pos, userect, 1.0f, Vector3_Zero, Vector3_Zero, 1.0f);

}