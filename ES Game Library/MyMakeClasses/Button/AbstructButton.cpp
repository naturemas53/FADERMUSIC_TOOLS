#include "AbstructButton.h"

const Vector2 AbstructButton::IMAGESIZE_ = Vector2(192.0f, 40.0f);
const RectWH AbstructButton::USERECT_ = RectWH(0, 0, 192, 40);

void AbstructButton::Draw(){

	this->ButtonDraw();

	this->NameDraw();

}

void AbstructButton::ButtonDraw(){

	SPRITE sp = this->SPRITES_;
	Vector3 pos = this->POS_;
	Vector2 scale = this->SCALE_;

	Rect userect = this->USERECT_;
	Vector2 imagesize = this->IMAGESIZE_;

	if (this->nowpush_){ 
		userect.top += (LONG)imagesize.y;
		userect.bottom += (LONG)imagesize.y;
	}

	SpriteBatch.Draw(*sp, pos, userect, 1.0f, Vector3_Zero, Vector3_Zero, scale);

}

void AbstructButton::NameDraw(){

	FONT font = this->NAMEFONT_;
	
	Vector2 scale = Vector2(1.7f, 1.7f);

	Vector2 pos = Vector3_Zero;
	pos.x = this->POS_.x + (5.0f * this->SCALE_.x);
	pos.y = this->POS_.y + (5.0f * this->SCALE_.y);

	std::wstring name = this->name_;

	SpriteBatch.DrawString(font, pos, Color(255, 255, 255), Vector2_One, Vector3_Zero, Vector3_Zero, name.c_str());

}