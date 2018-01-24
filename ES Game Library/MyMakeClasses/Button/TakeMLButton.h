#pragma once
#include "AbstructButton.h"

class AbstructMiddleLeft;

class TakeMLButton : public AbstructButton{

public:
	TakeMLButton(Vector3 pos, std::wstring name, AbstructMiddleLeft* haveml)
	:AbstructButton(pos,name,this->IMAGESIZE_){

		this->haveml_ = haveml;

	}
	~TakeMLButton() = default;

	AbstructMiddleLeft* GetMiddleLeft(){ return this->haveml_; }

private:

	AbstructMiddleLeft* haveml_;

};