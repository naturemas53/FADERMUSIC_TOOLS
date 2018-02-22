#include "HeightSettingMR.h"
#include "MenuMR.h"
#include "../Button/PMCalcButton.h"
#include "../Button/FreeButton.h"

HeightSettingMR::HeightSettingMR(std::vector<AbstructNote*>& selectnote){

	this->notes_ = selectnote;
	
	auto e_itr = this->notes_.end();
	e_itr--;

	this->height_ = (*e_itr)->GetHeight();

	this->heightbuttons_.push_back(new PMCalcButton(Vector3(90.0f, 20.0f, 0.0f), _T("<<<"), Vector2(40.0f, 20.0f), -0.1f));
	this->heightbuttons_.push_back(new PMCalcButton(Vector3(130.0f, 20.0f, 0.0f), _T("<<"), Vector2(30.0f, 20.0f), -0.01f));
	this->heightbuttons_.push_back(new PMCalcButton(Vector3(160.0f, 20.0f, 0.0f), _T("<"), Vector2(20.0f, 20.0f), -0.001f));
	this->heightbuttons_.push_back(new PMCalcButton(Vector3(230.0f, 20.0f, 0.0f), _T(">"), Vector2(20.0f, 20.0f), 0.001f));
	this->heightbuttons_.push_back(new PMCalcButton(Vector3(250.0f, 20.0f, 0.0f), _T(">>"), Vector2(30.0f, 20.0f), 0.01f));
	this->heightbuttons_.push_back(new PMCalcButton(Vector3(280.0f, 20.0f, 0.0f), _T(">>>"), Vector2(40.0f, 20.0f), 0.1f));

	Vector3 pos = Vector3_Zero;
	pos.y = this->SCREENSIZE_.y - 40.0f;

	this->desidebutton_ = new FreeButton(pos, _T("DESIDE"));

}

HeightSettingMR::~HeightSettingMR(){

	for (auto button : this->heightbuttons_) delete button;
	delete this->desidebutton_;

}

void HeightSettingMR::ClickCheck(Vector2 mouse_pos){

	for (auto heightbutton : this->heightbuttons_){
		if (heightbutton->CollisionPointToMe(mouse_pos, this->POS_)){

			this->height_ += heightbutton->GetValue();

			if (this->height_ < 0.0f) this->height_ = 0.0f;
			if (this->height_ > 1.0f) this->height_ = 1.0f;

			for (auto note : this->notes_){

				note->SetHeight(this->height_);

			}


		}
	}

	if (this->desidebutton_->CollisionPointToMe(mouse_pos, this->POS_)){

		for (auto note : this->notes_) note->SetSelectFlag(false);

		nextmr_ = new MenuMR();
		return;

	}

}

void HeightSettingMR::MyClassDraw(){

	FONT font = this->font_;

	for (auto heightbutton : this->heightbuttons_) heightbutton->Draw();

	SpriteBatch.DrawString(font, Vector2(20.0f, 20.0f), Color(255, 255, 255), _T("HEIGHT"));
	SpriteBatch.DrawString(font, Vector2(180.0f, 20.0f), Color(255, 255, 255), _T("%3.1f%%"), this->height_ * 100.0f);

	this->desidebutton_->Draw();

}