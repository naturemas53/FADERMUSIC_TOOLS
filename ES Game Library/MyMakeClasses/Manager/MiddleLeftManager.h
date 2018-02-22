#pragma once
#include "../../ESGLib.h"
#include "../Button/TakeMLButton.h"
#include <map>
#include <vector>
#include <memory>

class AbstructMiddleLeft;
class JukeBox;
class NoteManager;

class MiddleLeftManager{

public:

	MiddleLeftManager(std::shared_ptr<NoteManager> notemana_ptr, std::shared_ptr<JukeBox> jukebox_ptr);
	~MiddleLeftManager();

	void Draw();

	void ClickCheck(Vector2 mouse_pos);

	//�������͏㕔�̃{�^���ɂ���Đؑ�

private:

	std::map<const char*, AbstructMiddleLeft*> ml_map_;
	std::vector<TakeMLButton*> buttons_;
	std::shared_ptr<NoteManager> notemana_ptr_;
	AbstructMiddleLeft* nowmiddleleft_;

};