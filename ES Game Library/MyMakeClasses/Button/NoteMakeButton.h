#pragma once
#include "AbstructButton.h"

class NoteMakeButton : public AbstructButton{

public:

	NoteMakeButton(Vector3 pos) :
		AbstructButton(pos, _T("DEDIDE"), this->IMAGESIZE_){};
	virtual ~NoteMakeButton() = default;


private:


};