#include "PlayAreaManager.h"
#include "../PlayArea.h"

PlayAreaManager::PlayAreaManager(std::shared_ptr<NoteManager> notemana_ptr){

	for (int i = 0; i < 3;i++){

		this->playareas_.push_back(new PlayArea(Vector3(i * 426.0f, 360.0f, 0.0f),i));

	}

	this->notemana_ptr_ = notemana_ptr;

}

PlayAreaManager::~PlayAreaManager(){

	for (auto playarea : this->playareas_) delete playarea;
	// delete *(this->notemana_ptr_); ?

}

void PlayAreaManager::Draw(){

	for (auto playarea : this->playareas_){

		playarea->NoteDrawBegin();
		playarea->NoteDrawEnd();

		playarea->ScreenDraw();

	}

}