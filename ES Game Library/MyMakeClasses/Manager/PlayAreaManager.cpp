#include "PlayAreaManager.h"
#include "../PlayArea.h"
#include "NoteManager.h"

PlayAreaManager::PlayAreaManager(std::shared_ptr<NoteManager> notemana_ptr){

	for (int i = 0; i < 3;i++){

		this->playareas_.push_back(new PlayArea(Vector3(i * 426.0f, 360.0f, 0.0f),i));

	}

	this->notemana_ptr_ = notemana_ptr;

}

PlayAreaManager::~PlayAreaManager(){

	for (auto playarea : this->playareas_) delete playarea;

}

void PlayAreaManager::Draw(){

	Vector2 size;

	for (auto playarea : this->playareas_){

		size = playarea->GetSize();

		playarea->NoteDrawBegin();

		this->notemana_ptr_->DrawtoPlayArea(playarea->GetId(),size.y,size.x,playarea->GetNoteHitPos());

		playarea->NoteDrawEnd();

		playarea->ScreenDraw();

	}

}