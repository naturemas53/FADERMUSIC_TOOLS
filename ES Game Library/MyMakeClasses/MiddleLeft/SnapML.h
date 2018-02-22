#pragma once
#include "AbstructMiddleLeft.h"

class PMCalcButton;
class FreeButton;

class SnapML : public AbstructMiddleLeft{

public:
	SnapML();
	~SnapML();

	virtual void ClickCheck(Vector2 mouse_pos);

private:

	virtual void MyClassDraw();

	std::vector<PMCalcButton*> valuebuttons_;
	FreeButton* onoffbutton_;

};