#pragma once
#include "AbstructMiddleRight.h"
#include "SortRoot\AbstructSortRoot.h"
#include <vector>
#include <map>
#include <memory>

class AbstructButton;
class PlayAreaManager;

class SelectMR : public AbstructMiddleRight{

public:
	SelectMR(SELECTMODE selectmode);
	~SelectMR();

	virtual void ClickCheck(Vector2 mouse_pos);

	static void SetPlayAreaManager(std::shared_ptr<PlayAreaManager> areamana_ptr){

		SelectMR::areamana_ptr_ = areamana_ptr;

	}

private:

	virtual void MyClassDraw();
	void CheckButton(std::pair<std::string,AbstructButton*> button);

	static std::shared_ptr<PlayAreaManager> areamana_ptr_;

	std::map<std::string, AbstructButton*> buttons_;

	AbstructSortRoot* sortroot_;
	SELECTMODE selectmode_;
};