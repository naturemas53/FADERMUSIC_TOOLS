#pragma once
#include "../ESGLib.h"
#include "SpriteSingleton.h"

class PreviewSwitch{

public:
	PreviewSwitch(Vector3 pos) :
		POS_(pos),
		SIZE_(Vector2(320.0f, 80.0f)),
		USERECT_(RectWH(192, 0, 320, 80)),
		SPRITES_(StaticSprite.GetSprite()),
		nowpush_(false){};

	~PreviewSwitch() = default;

	void Draw();

	bool CollisionPointToMe(Vector2 mousepoint){

		if (POS_.x > mousepoint.x || (POS_.x + SIZE_.x) < mousepoint.x ||
			POS_.y > mousepoint.y || (POS_.y + SIZE_.y) < mousepoint.y){

			return false;

		}

		return true;
	}

	void SetNowPush(bool flag){ this->nowpush_ = flag; }

private:

	const Vector3 POS_;

	const Vector2 SIZE_;
	const RectWH USERECT_;
	const SPRITE SPRITES_;

	bool nowpush_;

};