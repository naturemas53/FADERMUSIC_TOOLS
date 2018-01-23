#pragma once
#include "AbstructMiddleRight.h"
#include <map>
#include <string>

class AbstructButton;

class MenuMR :public AbstructMiddleRight{

public:

	MenuMR();
	~MenuMR();

	virtual void ClickCheck(Vector2 mouse_pos);

private:

	virtual void MyClassDraw();

	void SetNextMR(const std::string& mapkey_);

	std::map<std::string, AbstructButton*> buttons_;

};