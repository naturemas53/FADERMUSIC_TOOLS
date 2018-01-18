#pragma once
#include "../../ESGLib.h"
#include <vector>
#include <memory>

class PlayArea;
class NoteManager;

class PlayAreaManager{

public:

	PlayAreaManager(std::shared_ptr<NoteManager> notemana_ptr);
	~PlayAreaManager();

	void Draw();



private:

	std::vector<PlayArea*> playareas_;
	std::shared_ptr<NoteManager> notemana_ptr_;

};