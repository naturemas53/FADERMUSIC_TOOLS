#pragma once
#include "../../ESGLib.h"
#include <memory>

class NoteManager;
class PlayAreaManager;
class AbstructMiddleRight;

class MiddleRightManager{

public:

	MiddleRightManager(std::shared_ptr<NoteManager> notemana_ptr,std::shared_ptr<PlayAreaManager> area_ptr);
	~MiddleRightManager();

	void Draw();

	void ClickCheck(Vector2 mouse_pos);

private:

	std::shared_ptr<NoteManager> notemana_ptr_;
	AbstructMiddleRight* nowmiddleright_;

};