#pragma once
#include "AbstructButton.h"

class NoteMakeButton : public AbstructButton{

public:

	NoteMakeButton(Vector3 pos) :
		AbstructButton(pos, _T("DEDIDE"), Vector2(this->IMAGESIZE_.x / 2.0f,this->IMAGESIZE_.y)){};
	virtual ~NoteMakeButton() = default;


private:


};