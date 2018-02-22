#pragma once
#include "AbstructMiddleRight.h"
#include <list>
#include <vector>

class PMCalcButton;
class FreeButton;

class HeightSettingMR : public AbstructMiddleRight{

public:
	HeightSettingMR(std::vector<AbstructNote*>& selectnote);
	~HeightSettingMR();

	virtual void ClickCheck(Vector2 mouse_pos);

private:

	virtual void MyClassDraw();


	std::vector<AbstructNote*> notes_;

	std::list<PMCalcButton*> heightbuttons_;
	FreeButton* desidebutton_;

	float height_;

};