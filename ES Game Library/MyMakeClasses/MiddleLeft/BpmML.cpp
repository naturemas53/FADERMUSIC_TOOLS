#include "BpmML.h"
#include <string>

BpmML::BpmML(){

	this->bpmpos_ = Vector3(650.0f, 40.0f, 0.0f);

	float invalue = 100.0f;

	Vector3 pos = bpmpos_;
	pos.x += 70.0f;
	pos.y -= 20.0f;
	std::wstring str = _T("Å™");

	for (int i = 0; i < 6; i++){

		this->bpmbuttons_.push_back(new PMCalcButton(pos, str.c_str(), Vector2(20.0f, 20.0f), invalue));

		if (i % 3 == 2){

			invalue = -100.0f;
			pos = bpmpos_;
			pos.x += 70.0f;
			pos.y += 20.0f;
			str.clear();
			str = _T("Å´");

		}
		else{

			invalue /= 10.0f;
			pos.x += 25.0f;

		}

	}


	this->timingpos_ = Vector3(650.0f, 120.0f, 0.0f);

	invalue = 100000.0f;

	pos = timingpos_;
	pos.x += 70.0f;
	pos.y -= 20.0f;
	str = _T("Å™");

	for (int i = 0; i < 12; i++){

		this->timingbuttons_.push_back(new PMCalcButton(pos, str.c_str(), Vector2(20.0f, 20.0f), invalue));

		if (i % 6 == 5){

			invalue = -100000.0f;
			pos = timingpos_;
			pos.x += 70.0f;
			pos.y += 20.0f;
			str.clear();
			str = _T("Å´");

		}
		else{

			invalue /= 10.0f;
			pos.x += 25.0f;

		}

	}

	this->desidebutton_ = new FreeButton(Vector3(480.0f + ((480.0f - 192.0f) / 2.0f),240.0f,0.0f),_T("DESIDE"));

	this->bpm_ = 0;
	this->timing_ = 0;

}

BpmML::~BpmML(){

	for (auto button : this->bpmbuttons_) delete button;
	for (auto button : this->timingbuttons_) delete button;

	delete this->desidebutton_;
}

void BpmML::ClickCheck(Vector2 mouse_pos){

		int value;

		for (auto button : this->bpmbuttons_){

			if (button->CollisionPointToMe(mouse_pos, this->POS_)){

				value = (int)button->GetValue();

				this->bpm_ += value;

				if (this->bpm_ < 0) this->bpm_ = 0;
				if (this->bpm_ > 999) this->bpm_ = 999;

			}

		}

		for (auto button : this->timingbuttons_){

			if (button->CollisionPointToMe(mouse_pos, this->POS_)){

				value = (int)button->GetValue();

				this->timing_ += value;

				if (this->timing_ < 0) this->timing_ = 0;
				if (this->timing_ > 999999) this->timing_ = 999999;

			}

		}

		if (this->desidebutton_->CollisionPointToMe(mouse_pos, this->POS_)){

			BPM_DATA data = BPM_DATA(this->timing_, this->bpm_);

				this->notemana_ptr_->AddBpmData(data);

		}

}

void BpmML::MyClassDraw(){

	for (auto button : this->bpmbuttons_) button->Draw();
	for (auto button : this->timingbuttons_) button->Draw();

	this->desidebutton_->Draw();

	Vector2 pos = Vector2_Zero;
	pos.x = this->bpmpos_.x;
	pos.y = this->bpmpos_.y;
	FONT font = this->font_;

	SpriteBatch.DrawString(font,pos,Color(0,0,0),_T("BPM"));

	pos.x += 70.0f;
	int value = this->bpm_;
	int division = 100;
	for (int i = 0; i < 3; i++){

		SpriteBatch.DrawString(font, pos, Color(0, 0, 0), _T("%d"),(value / division) % 10);
		division /= 10;
		pos.x += 25.0f;
	}

	pos.x = this->timingpos_.x;
	pos.y = this->timingpos_.y;
	SpriteBatch.DrawString(font, pos, Color(0, 0, 0), _T("TIMING"));

	pos.x += 70.0f;
	value = this->timing_;
	division = 100000;
	for (int i = 0; i < 6; i++){

		SpriteBatch.DrawString(font, pos, Color(0, 0, 0), _T("%d"), (value / division) % 10);
		division /= 10;
		pos.x += 25.0f;
	}

	this->notemana_ptr_->BpmDataDraw(Vector2_One * 3.0f);

}