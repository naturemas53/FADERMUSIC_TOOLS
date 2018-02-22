#include "SnapML.h"
#include "../Button/PMCalcButton.h"
#include "../Button/FreeButton.h"

SnapML::SnapML(){

	this->onoffbutton_ = new FreeButton(Vector3(160.0f, 20.0f, 0.0f),_T("SNAP ON"));

	this->valuebuttons_.push_back(new PMCalcButton(Vector3(160.0f, 80.0f, 0.0f), _T("<"), Vector2(20.0f, 20.0f), -1.0f));
	this->valuebuttons_.push_back(new PMCalcButton(Vector3(230.0f, 80.0f, 0.0f), _T(">"), Vector2(20.0f, 20.0f), 1.0f));

}

SnapML::~SnapML(){

	delete this->onoffbutton_;
	for (auto button : this->valuebuttons_){

		delete button;

	}

}

void SnapML::ClickCheck(Vector2 mouse_pos){

	if (this->onoffbutton_->CollisionPointToMe(mouse_pos,this->POS_)){

		this->notemana_ptr_->SnapFlagChenge();

	}

	for (auto button : this->valuebuttons_){

		if (button->CollisionPointToMe(mouse_pos,this->POS_)){

			int value = button->GetValue();
			this->notemana_ptr_->SnapCountChenge(value);

		}

	}

}

void SnapML::MyClassDraw(){

	FONT font = this->font_;

	if (this->notemana_ptr_->GetSnapFlag()){

		this->onoffbutton_->NameChange(_T("SNAP ON"));

	}
	else{

		this->onoffbutton_->NameChange(_T("SNAP OFF"));

	}

	this->onoffbutton_->Draw();
	for (auto button : this->valuebuttons_){

		button->Draw();

	}

	SpriteBatch.DrawString(font, Vector2(5.0f, 80.0f), Color(0, 0, 0), _T("SNAP VALUE"));
	SpriteBatch.DrawString(font, Vector2(180.0f, 80.0f), Color(0, 0, 0), _T("%3d"),this->notemana_ptr_->GetSnapCount());

	//SpriteBatch.DrawString(font, Vector2(180.0f, 80.0f), Color(255, 255, 255), _T("NOW SNAP TIME"));
	//SpriteBatch.DrawString(font, Vector2(180.0f, 40.0f), Color(255, 255, 255), _T("%d")); スナップ値

}