#include "SongSelectML.h"
#include "../Button/FreeButton.h"
#include "../JukeBox.h"

SongSelectML::SongSelectML(std::shared_ptr<JukeBox> jukebox_ptr){

	this->jukebox_ptr_ = jukebox_ptr;

	Vector2 screensize = this->SCREENSIZE_;
	Vector2 buttonsize = Vector2(192.0f, 40.0f);
	Vector3 buttonpos = Vector3((screensize.x - buttonsize.x) / 2.0f, (screensize.y - buttonsize.y) / 2.0f, 0.0f);

	this->button_ = new FreeButton(buttonpos,_T("SONGSELECT"));

}

SongSelectML::~SongSelectML(){

	delete this->button_;

}

void SongSelectML::MyClassDraw(){

	this->button_->Draw();

}

void SongSelectML::ClickCheck(Vector2 mouse_pos){

		if (this->button_->CollisionPointToMe(mouse_pos,this->POS_)){

			this->jukebox_ptr_->ChangeMusic();

		}
}