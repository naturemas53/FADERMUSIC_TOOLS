#pragma once

#include "../SpriteSingleton.h"
#include <string>

class AbstructButton{

public:

	virtual ~AbstructButton() = default;

	virtual void Draw();

	bool CollisionPointToMe(Vector2 mousepoint,Vector3 correctionpos = Vector3_Zero){

		Vector3 pos = this->POS_ + correctionpos;
		Vector2 size = this->SIZE_;

		if (pos.x > mousepoint.x || (pos.x + size.x) < mousepoint.x ||
			pos.y > mousepoint.y || (pos.y + size.y) < mousepoint.y){

			return false;

		}

		return true;
	}

	void SetNowPush(bool flag){ this->nowpush_ = flag; }
	bool IsPushed(Vector2 mousepoint, Vector3 correctionpos = Vector3_Zero){

		return (this->CollisionPointToMe(mousepoint, correctionpos) && this->nowpush_);

	}

protected:

	AbstructButton(Vector3 pos,std::wstring name,Vector2 size):
	POS_(pos),
	SIZE_(size),
	SCALE_(Vector2((size.x / IMAGESIZE_.x), (size.y / IMAGESIZE_.y))),
	SPRITES_(StaticSprite.GetSprite()),
	NAMEFONT_(GraphicsDevice.CreateDefaultFont()),
	nowpush_(false),
	name_(name)
	{};

	virtual void ButtonDraw();
	virtual void NameDraw();

	const Vector3 POS_;
	
	static const Vector2 IMAGESIZE_;
	static const RectWH USERECT_;
	const Vector2 SIZE_;
	const Vector2 SCALE_;
	const SPRITE SPRITES_;
	const FONT NAMEFONT_;
	
	std::wstring name_;
	bool nowpush_;

};
