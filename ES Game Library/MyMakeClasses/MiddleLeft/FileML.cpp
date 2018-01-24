#include "FileML.h"
#include "../InputSingleton.h"

FileML::FileML(){

	float pos_x = ((this->SCREENSIZE_.x/ 2.0f) - 192.0f) / 2.0f;

	this->openbutton_ = new FreeButton(Vector3(pos_x, (this->SCREENSIZE_.y - 40.0f) / 2.0f, 0.0f), _T("IMPORT"));
	this->savebutton_ = new FreeButton(Vector3((this->SCREENSIZE_.x / 2.0f) + pos_x, (this->SCREENSIZE_.y - 40.0f) / 2.0f, 0.0f), _T("EXPORT"));

}

FileML::~FileML(){

	delete this->openbutton_;
	delete this->savebutton_;

}

void FileML::ClickCheck(Vector2 mouse_pos){

	if (StaticInput.IsMouseButtonPressed(Mouse_Button1)){

		if (this->openbutton_->CollisionPointToMe(mouse_pos,this->POS_)){

			this->notemana_ptr_->MusicScoreImport();

		}

		if (this->savebutton_->CollisionPointToMe(mouse_pos, this->POS_)){

			this->notemana_ptr_->MusicScoreExport();

		}

	}

}

void FileML::MyClassDraw(){

	this->openbutton_->Draw();
	this->savebutton_->Draw();

}