#include "SettingMR.h"
#include "../Button/PMCalcButton.h"
#include "../Button/FreeButton.h"
#include "MenuMR.h"

SettingMR::SettingMR(bool uniteflag, std::vector<AbstructNote*>& selectnote){

	this->uniteflag_ = uniteflag;
	this->notes_ = selectnote;

	if (this->uniteflag_){

		auto itr = this->notes_.end();
		itr--;

		this->unitenote_ = (*itr);
		
		this->height_ = (*itr)->GetHeight();
		this->timing_ = (*itr)->GetTiming();

	}
	else{

		this->height_ = 0.0f;
		this->timing_ = 0;

		this->unitenote_ = nullptr;

	}

	this->heightbuttons_.push_back(new PMCalcButton(Vector3(90.0f, 20.0f, 0.0f), _T("<<<"), Vector2(40.0f, 20.0f), -0.1f));
	this->heightbuttons_.push_back(new PMCalcButton(Vector3(130.0f, 20.0f, 0.0f), _T("<<"), Vector2(30.0f, 20.0f), -0.01f));
	this->heightbuttons_.push_back(new PMCalcButton(Vector3(160.0f, 20.0f, 0.0f), _T("<"), Vector2(20.0f, 20.0f), -0.001f));
	this->heightbuttons_.push_back(new PMCalcButton(Vector3(230.0f, 20.0f, 0.0f), _T(">"), Vector2(20.0f, 20.0f), 0.001f));
	this->heightbuttons_.push_back(new PMCalcButton(Vector3(250.0f, 20.0f, 0.0f), _T(">>"), Vector2(30.0f, 20.0f), 0.01f));
	this->heightbuttons_.push_back(new PMCalcButton(Vector3(280.0f, 20.0f, 0.0f), _T(">>>"), Vector2(40.0f, 20.0f), 0.1f));

	this->timingbuttons_.push_back(new PMCalcButton(Vector3(145.0f, 50.0f, 0.0f), _T("ª"), Vector2(20.0f, 20.0f), 100000.0f));
	this->timingbuttons_.push_back(new PMCalcButton(Vector3(170.0f, 50.0f, 0.0f), _T("ª"), Vector2(20.0f, 20.0f), 10000.0f));
	this->timingbuttons_.push_back(new PMCalcButton(Vector3(195.0f, 50.0f, 0.0f), _T("ª"), Vector2(20.0f, 20.0f), 1000.0f));
	this->timingbuttons_.push_back(new PMCalcButton(Vector3(220.0f, 50.0f, 0.0f), _T("ª"), Vector2(20.0f, 20.0f), 100.0f));
	this->timingbuttons_.push_back(new PMCalcButton(Vector3(245.0f, 50.0f, 0.0f), _T("ª"), Vector2(20.0f, 20.0f), 10.0f));
	this->timingbuttons_.push_back(new PMCalcButton(Vector3(270.0f, 50.0f, 0.0f), _T("ª"), Vector2(20.0f, 20.0f), 1.0f));
	this->timingbuttons_.push_back(new PMCalcButton(Vector3(145.0f, 90.0f, 0.0f), _T("«"), Vector2(20.0f, 20.0f), -100000.0f));
	this->timingbuttons_.push_back(new PMCalcButton(Vector3(170.0f, 90.0f, 0.0f), _T("«"), Vector2(20.0f, 20.0f),-10000.0f));
	this->timingbuttons_.push_back(new PMCalcButton(Vector3(195.0f, 90.0f, 0.0f), _T("«"), Vector2(20.0f, 20.0f),-1000.0f));
	this->timingbuttons_.push_back(new PMCalcButton(Vector3(220.0f, 90.0f, 0.0f), _T("«"), Vector2(20.0f, 20.0f),-100.0f));
	this->timingbuttons_.push_back(new PMCalcButton(Vector3(245.0f, 90.0f, 0.0f), _T("«"), Vector2(20.0f, 20.0f),-10.0f));
	this->timingbuttons_.push_back(new PMCalcButton(Vector3(270.0f, 90.0f, 0.0f), _T("«"), Vector2(20.0f, 20.0f),-1.0f));

	Vector3 pos = Vector3_Zero;
	pos.y = this->SCREENSIZE_.y - 40.0f;

	this->desidebutton_ = new FreeButton(pos, _T("DESIDE"));

}

SettingMR::~SettingMR(){

	for (auto note : this->notes_){

		note->SetSelectFlag(false);

	}

	for (auto heightbutton : this->heightbuttons_) delete heightbutton;
	for (auto timingbutton : this->timingbuttons_) delete timingbutton;

	delete this->desidebutton_;

}

void SettingMR::MyClassDraw(){

	FONT font = this->font_;

	for (auto heightbutton : this->heightbuttons_) heightbutton->Draw();

	SpriteBatch.DrawString(font, Vector2(20.0f, 20.0f), Color(255, 255, 255), _T("HEIGHT"));
	SpriteBatch.DrawString(font, Vector2(180.0f, 20.0f), Color(255, 255, 255), _T("%3.1f%%"), this->height_ * 100.0f);

	for (auto timingbutton : this->timingbuttons_) timingbutton->Draw();

	SpriteBatch.DrawString(font, Vector2(20.0f, 70.0f), Color(255, 255, 255), _T("TIMING"));

	int timing = this->timing_;

	if (timing < 0){

		SpriteBatch.DrawString(font, Vector2(125.0f, 70.0f), Color(255, 255, 255), _T("-"));
		timing *= -1;

	}

	SpriteBatch.DrawString(font, Vector2(150.0f, 70.0f), Color(255, 255, 255), _T("%d"), timing / 100000);
	SpriteBatch.DrawString(font, Vector2(175.0f, 70.0f), Color(255, 255, 255), _T("%d"), (timing / 10000) % 10);
	SpriteBatch.DrawString(font, Vector2(200.0f, 70.0f), Color(255, 255, 255), _T("%d"), (timing / 1000) % 10);
	SpriteBatch.DrawString(font, Vector2(225.0f, 70.0f), Color(255, 255, 255), _T("%d"), (timing / 100) % 10);
	SpriteBatch.DrawString(font, Vector2(250.0f, 70.0f), Color(255, 255, 255), _T("%d"), (timing / 10) % 10);
	SpriteBatch.DrawString(font, Vector2(275.0f, 70.0f), Color(255, 255, 255), _T("%d"), this->timing_ % 10);

	this->desidebutton_->Draw();

}

void SettingMR::ClickCheck(Vector2 mouse_pos){

		this->PressCheck(mouse_pos);

		if (this->desidebutton_->CollisionPointToMe(mouse_pos, this->POS_)){

			for (auto note : this->notes_) note->SetSelectFlag(false);

			nextmr_ = new MenuMR();
			return;

		}

}

void SettingMR::PressCheck(Vector2 mouse_pos){

	for (auto heightbutton : this->heightbuttons_){
		if (heightbutton->CollisionPointToMe(mouse_pos, this->POS_)){
		
			this->height_ += heightbutton->GetValue();

			if (this->uniteflag_){
				if (this->height_ < 0.0f) this->height_ = 0.0f;
				if (this->height_ > 1.0f) this->height_ = 1.0f;
			
				for (auto note : this->notes_){

					note->SetHeight(this->height_);

				}

			}
			else{

				if (this->height_ < -1.0f){
					this->height_ = -1.0f;
					return;
				}
				if (this->height_ > 1.0f){
					this->height_ = 1.0f;
					return;
				}

				float height;

				for (auto note : this->notes_){

					height = note->GetHeight();
					height += heightbutton->GetValue();

					note->SetHeight(height);

				}

			}
		
		}
			
	}

	for (auto timingbutton : this->timingbuttons_){
		if (timingbutton->CollisionPointToMe(mouse_pos, this->POS_)){
		
			//this->timing_ += (int)timingbutton->GetValue();
			int value = timingbutton->GetValue();

			if (this->uniteflag_){

				//if (this->timing_ < 0) this->timing_ = 0;
				//if (this->timing_ > 999999) this->timing_ = 999999;

				//for (auto note : this->notes_){

				//	note->SetTiming(this->timing_);

				//}

				this->notemana_ptr_->TimingUnite(value,this->notes_,this->unitenote_);
				this->timing_ = this->unitenote_->GetTiming();

			}
			else{

				this->timing_ += value;

				if (this->timing_ < -999999) {
					this->timing_ = -999999;
					return;
				}
				if (this->timing_ > 999999) {
					this->timing_ = 999999;
					return;
				}

				//int timing;

				//for (auto note : this->notes_){

				//	timing = note->GetTiming();
				//	timing += (int)timingbutton->GetValue();

				//	note->SetTiming(timing);

				//}

				this->notemana_ptr_->TimingChenge(value, this->notes_);



			}
		
		}
			
	}

}