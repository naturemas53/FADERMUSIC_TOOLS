#include "PlayAreaManager.h"
#include "PlayArea.h"

PlayAreaManager::PlayAreaManager(){

	for (int i = 0; i < 3;i++){

		this->playareas_.push_back(new PlayArea(Vector3(i * 426.0f, 360.0f, 0.0f),i));

	}

}

PlayAreaManager::~PlayAreaManager(){

	for (auto playarea : this->playareas_) delete playarea;

}

void PlayAreaManager::Draw(){

	for (auto playarea : this->playareas_){

		playarea->NoteDrawBegin();
		playarea->NoteDrawEnd();

		playarea->ScreenDraw();

	}

}