#include "AbstructNote.h"
#include "../SpriteSingleton.h"

SPRITE AbstructNote::sp_ = nullptr;

AbstructNote::AbstructNote(RectWH userect, NoteType type) :
USERECT_(userect),
MARKUSERECT_(RectWH(282,160,30,30)),
TYPE_(type),
SIZE_(Vector2(30.0f, 30.0f)){

	if (this->sp_ == nullptr){

		this->sp_ = StaticSprite.GetSprite();

	}

	this->clapflag_ = true;
	this->selectflag_ = false;

}

void AbstructNote::LayerDraw(float drawareaheight, float drawareawidth, float notehit_xpos, DWORD nowtime){

	SPRITE sp = this->sp_;
	Rect userect = this->USERECT_;

	Vector3 pos = this->CalcPos(drawareaheight, drawareawidth, notehit_xpos, nowtime);
	pos.y = (drawareaheight - this->SIZE_.y) / 2.0f;

	DWORD betweentime = this->timing_ - nowtime;
	float timingrate = (float)(1000 - betweentime) / 1000.0f;

	float pal = (timingrate >= 1.0f) ? 0.5f : 1.0f;

	SpriteBatch.Draw(*sp,pos,userect,pal);

	if (this->selectflag_){

		userect = this->MARKUSERECT_;

		SpriteBatch.Draw(*sp, pos, userect,1.0f);
	}

}

bool AbstructNote::LayerClickCheck(
	Vector2 mouse_pos,
	Vector3 correctionpos,
	float drawareaheight,
	float drawareawidth,
	float notehit_xpos,
	DWORD nowtime){

	Vector2 size = this->SIZE_;

	Vector3 pos = this->CalcPos(drawareaheight,drawareawidth,notehit_xpos,nowtime);
	pos.y = (drawareawidth - size.y) / 2.0f;
	pos += correctionpos;

	if (mouse_pos.x < pos.x || mouse_pos.x > pos.x + size.x||
		mouse_pos.y < pos.y || mouse_pos.x > pos.y + size.y){

		return false;

	}

	return true;

}

bool AbstructNote::PlayAreaClickCheck(
	Vector2 mouse_pos,
	Vector3 correctionpos,
	float drawareaheight,
	float drawareawidth,
	float notehit_xpos,
	DWORD nowtime){

	Vector2 size = this->SIZE_;

	Vector3 pos = this->CalcPos(drawareaheight, drawareawidth, notehit_xpos, nowtime);

	if (pos.x > drawareawidth - size.x || pos.x < 0.0f) return false;

	pos += correctionpos;

	if (mouse_pos.x < pos.x || mouse_pos.x > pos.x + size.x ||
		mouse_pos.y < pos.y || mouse_pos.y > pos.y + size.y){

		return false;

	}

	return true;

}

Vector3 AbstructNote::CalcPos(float drawareaheight, float drawareawidth, float notehit_xpos, DWORD nowtime){

	Vector2 size = this->SIZE_;

	notehit_xpos -= size.x / 2.0f; //(ノートサイズの半分)
	drawareawidth += size.x;//30.0fはノートの大きさ
	drawareaheight -= size.y;

	float betweenwidth = drawareawidth - notehit_xpos;
	long betweentime = this->timing_ - nowtime;
	float timingrate = (float)(1000 - betweentime) / 1000.0f;

	float x_pos = drawareawidth - (timingrate * betweenwidth);
	float y_pos = drawareaheight * this->height_;

	Vector3 pos = Vector3_Zero;
	pos.x = x_pos;
	pos.y = y_pos;

	return pos;

}