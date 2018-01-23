#pragma once
#include "../../ESGLib.h"
#include "../PlayArea.h"
#include "NoteManager.h"
#include <vector>
#include <memory>

class PlayAreaManager{

public:

	PlayAreaManager(std::shared_ptr<NoteManager> notemana_ptr);
	~PlayAreaManager();

	void Draw();

	AbstructNote* ClickCheck(Vector2 mouse_pos){

		Vector2 size;
		int id;
		float hitpos;
		Vector3 pos;

		AbstructNote* getnote = nullptr;

		for (auto playarea : this->playareas_){

			size = playarea->GetSize();
			id = playarea->GetId();
			hitpos = playarea->GetNoteHitPos();
			pos = playarea->GetPos();

			getnote = this->notemana_ptr_->PlayAreaClickCheck(mouse_pos, id, size.y, size.x, hitpos, pos);

			if (getnote != nullptr) break;

		}

		return getnote;

	}


private:

	std::vector<PlayArea*> playareas_;
	std::shared_ptr<NoteManager> notemana_ptr_;

};