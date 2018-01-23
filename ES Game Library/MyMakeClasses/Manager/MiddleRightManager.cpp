#include "MiddleRightManager.h"
#include "../MiddleRight/AbstructMiddleRight.h"
#include "../MiddleRight/MenuMR.h"
#include "../MiddleRight/SelectMR.h"

MiddleRightManager::MiddleRightManager(std::shared_ptr<NoteManager> notemana_ptr, std::shared_ptr<PlayAreaManager> areamana_ptr){

	AbstructMiddleRight::SetNoteManager(notemana_ptr);
	SelectMR::SetPlayAreaManager(areamana_ptr);

	this->notemana_ptr_ = notemana_ptr;

	this->nowmiddleright_ = new MenuMR();


}

MiddleRightManager::~MiddleRightManager(){

	delete this->nowmiddleright_;

}

void MiddleRightManager::Draw(){

	this->nowmiddleright_->Draw();

}

void MiddleRightManager::ClickCheck(Vector2 mouse_pos){

	this->nowmiddleright_->ClickCheck(mouse_pos);

	AbstructMiddleRight* nextmr = this->nowmiddleright_->GetNextMR();

	if (nextmr != nullptr){

		delete this->nowmiddleright_;
		
		this->nowmiddleright_ = nextmr;

	}
}