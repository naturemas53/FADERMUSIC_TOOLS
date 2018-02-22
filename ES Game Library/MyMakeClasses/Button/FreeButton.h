#pragma once
#include "AbstructButton.h"

class FreeButton : public AbstructButton{

public:
	FreeButton(Vector3 pos, std::wstring name) :
		AbstructButton(pos, name, this->IMAGESIZE_){};
	~FreeButton() = default;

	void NameChange(std::wstring name){ this->name_ = name; }

private:

};