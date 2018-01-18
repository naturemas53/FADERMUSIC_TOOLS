#include "NoteManager.h"
#include "../Note/SingleNote.h"
#include "../JukeBox.h"
#include <math.h>

NoteManager::NoteManager(std::shared_ptr<JukeBox> jukebox_ptr){

	this->jukebox_ptr_ = jukebox_ptr;

}

NoteManager::~NoteManager(){

	for (auto note : this->notes_) delete note;

}

void NoteManager::DrawtoLayer(int layerid, float layerheight, float layerwidth, float layernotehit_x){

	DWORD nowtime = this->jukebox_ptr_->GetNowTimeMiliSec();

	for (auto note : this->notes_){

		if (labs((long)note->GetTiming() - nowtime) < 1000){

			if (note->GetLayer() == layerid){

				note->SimpleDraw(layerheight, layerwidth, layernotehit_x, nowtime);

			}

		}

	}

}