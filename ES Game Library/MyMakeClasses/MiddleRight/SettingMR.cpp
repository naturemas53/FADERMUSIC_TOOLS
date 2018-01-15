#include "SettingMR.h"
#include "../Button/PMCalcButton.h"
#include "../InputSingleton.h"

SettingMR::SettingMR(){

	this->layer_ = 0;
	this->area_ = 0;
	this->height_ = 1.0f;
	this->timing_ = 0;

	this->layerbuttons_.push_back(new PMCalcButton(Vector3(170.0f,0.0f,0.0f),_T("<"),Vector2(20.0f,20.0f),-1.0f));
	this->layerbuttons_.push_back(new PMCalcButton(Vector3(250.0f, 0.0f, 0.0f), _T(">"), Vector2(20.0f, 20.0f), 1.0f));

	this->areabuttons_.push_back(new PMCalcButton(Vector3(170.0f, 30.0f, 0.0f), _T("<"), Vector2(20.0f, 20.0f), -1.0f));
	this->areabuttons_.push_back(new PMCalcButton(Vector3(250.0f, 30.0f, 0.0f), _T(">"), Vector2(20.0f, 20.0f), 1.0f));

	this->heightbuttons_.push_back(new PMCalcButton(Vector3(90.0f, 60.0f, 0.0f), _T("<<<"), Vector2(40.0f, 20.0f), -0.1f));
	this->heightbuttons_.push_back(new PMCalcButton(Vector3(130.0f, 60.0f, 0.0f), _T("<<"), Vector2(30.0f, 20.0f), -0.01f));
	this->heightbuttons_.push_back(new PMCalcButton(Vector3(160.0f, 60.0f, 0.0f), _T("<"), Vector2(20.0f, 20.0f), -0.001f));
	this->heightbuttons_.push_back(new PMCalcButton(Vector3(230.0f, 60.0f, 0.0f), _T(">"), Vector2(20.0f, 20.0f), 0.001f));
	this->heightbuttons_.push_back(new PMCalcButton(Vector3(250.0f, 60.0f, 0.0f), _T(">>"), Vector2(30.0f, 20.0f), 0.01f));
	this->heightbuttons_.push_back(new PMCalcButton(Vector3(280.0f, 60.0f, 0.0f), _T(">>>"), Vector2(40.0f, 20.0f), 0.1f));

	this->timingbuttons_.push_back(new PMCalcButton(Vector3(145.0f, 90.0f, 0.0f), _T("ª"), Vector2(20.0f, 20.0f), 100000.0f));
	this->timingbuttons_.push_back(new PMCalcButton(Vector3(170.0f, 90.0f, 0.0f), _T("ª"), Vector2(20.0f, 20.0f), 10000.0f));
	this->timingbuttons_.push_back(new PMCalcButton(Vector3(195.0f, 90.0f, 0.0f), _T("ª"), Vector2(20.0f, 20.0f), 1000.0f));
	this->timingbuttons_.push_back(new PMCalcButton(Vector3(220.0f, 90.0f, 0.0f), _T("ª"), Vector2(20.0f, 20.0f), 100.0f));
	this->timingbuttons_.push_back(new PMCalcButton(Vector3(245.0f, 90.0f, 0.0f), _T("ª"), Vector2(20.0f, 20.0f), 10.0f));
	this->timingbuttons_.push_back(new PMCalcButton(Vector3(270.0f, 90.0f, 0.0f), _T("ª"), Vector2(20.0f, 20.0f), 1.0f));
	this->timingbuttons_.push_back(new PMCalcButton(Vector3(145.0f, 130.0f, 0.0f), _T("«"), Vector2(20.0f, 20.0f), -100000.0f));
	this->timingbuttons_.push_back(new PMCalcButton(Vector3(170.0f, 130.0f, 0.0f), _T("«"), Vector2(20.0f, 20.0f),-10000.0f));
	this->timingbuttons_.push_back(new PMCalcButton(Vector3(195.0f, 130.0f, 0.0f), _T("«"), Vector2(20.0f, 20.0f),-1000.0f));
	this->timingbuttons_.push_back(new PMCalcButton(Vector3(220.0f, 130.0f, 0.0f), _T("«"), Vector2(20.0f, 20.0f),-100.0f));
	this->timingbuttons_.push_back(new PMCalcButton(Vector3(245.0f, 130.0f, 0.0f), _T("«"), Vector2(20.0f, 20.0f),-10.0f));
	this->timingbuttons_.push_back(new PMCalcButton(Vector3(270.0f, 130.0f, 0.0f), _T("«"), Vector2(20.0f, 20.0f),-1.0f));


}

SettingMR::~SettingMR(){

	for (auto layerbutton : this->layerbuttons_) delete layerbutton;
	for (auto areabutton : this->areabuttons_) delete areabutton;
	for (auto heightbutton : this->heightbuttons_) delete heightbutton;
	for (auto timingbutton : this->timingbuttons_) delete timingbutton;
}

void SettingMR::MyClassDraw(){

	FONT font = this->font_;

	for (auto layerbutton : this->layerbuttons_) layerbutton->Draw();

	SpriteBatch.DrawString(font, Vector2(20.0f, 0.0f), Color(255, 255, 255), _T("LAYER"));
	SpriteBatch.DrawString(font, Vector2(215.0f, 0.0f), Color(255, 255, 255), _T("%d"),this->layer_);

	for (auto areabutton : this->areabuttons_) areabutton->Draw();

	SpriteBatch.DrawString(font, Vector2(20.0f, 30.0f), Color(255, 255, 255), _T("PLAYAREA"));
	SpriteBatch.DrawString(font, Vector2(215.0f, 30.0f), Color(255, 255, 255), _T("%d"), this->area_);

	for (auto heightbutton : this->heightbuttons_) heightbutton->Draw();

	SpriteBatch.DrawString(font, Vector2(20.0f, 60.0f), Color(255, 255, 255), _T("HEIGHT"));
	SpriteBatch.DrawString(font, Vector2(180.0f, 60.0f), Color(255, 255, 255), _T("%3.1f%%"), this->height_ * 100.0f);

	for (auto timingbutton : this->timingbuttons_) timingbutton->Draw();

	SpriteBatch.DrawString(font, Vector2(20.0f, 110.0f), Color(255, 255, 255), _T("TIMING"));
	SpriteBatch.DrawString(font, Vector2(150.0f, 110.0f), Color(255, 255, 255), _T("%d"), this->timing_ / 100000);
	SpriteBatch.DrawString(font, Vector2(175.0f, 110.0f), Color(255, 255, 255), _T("%d"), (this->timing_ / 10000) % 10 );
	SpriteBatch.DrawString(font, Vector2(200.0f, 110.0f), Color(255, 255, 255), _T("%d"), (this->timing_ / 1000) % 10 );
	SpriteBatch.DrawString(font, Vector2(225.0f, 110.0f), Color(255, 255, 255), _T("%d"), (this->timing_ / 100) % 10);
	SpriteBatch.DrawString(font, Vector2(250.0f, 110.0f), Color(255, 255, 255), _T("%d"), (this->timing_ / 10) % 10);
	SpriteBatch.DrawString(font, Vector2(275.0f, 110.0f), Color(255, 255, 255), _T("%d"), this->timing_ % 10);

}

void SettingMR::ClickCheck(Vector2 mouse_pos){

	if (StaticInput.IsMouseButtonPressed(Mouse_Button1)){

		this->PressCheck(mouse_pos);

	}
	else{

		this->ReleaseRun(mouse_pos);

	}

}

void SettingMR::PressCheck(Vector2 mouse_pos){

	for (auto layerbutton : this->layerbuttons_){
		if (layerbutton->CollisionPointToMe(mouse_pos, this->POS_))
			layerbutton->SetNowPush(true);
	}

	for (auto areabutton : this->areabuttons_){
		if (areabutton->CollisionPointToMe(mouse_pos, this->POS_))
			areabutton->SetNowPush(true);
	}

	for (auto heightbutton : this->heightbuttons_){
		if (heightbutton->CollisionPointToMe(mouse_pos, this->POS_))
			heightbutton->SetNowPush(true);
	}

	for (auto timingbutton : this->timingbuttons_){
		if (timingbutton->CollisionPointToMe(mouse_pos, this->POS_))
			timingbutton->SetNowPush(true);
	}

}

void SettingMR::ReleaseRun(Vector2 mouse_pos){

	for (auto layerbutton : this->layerbuttons_){
		if (layerbutton->IsPushed(mouse_pos, this->POS_)){

			layerbutton->CalcValue(this->layer_);

			if (this->layer_ < 0) this->layer_ = 0;
			if (this->layer_ > 7) this->layer_ = 7;

		}

		layerbutton->SetNowPush(false);
	}

	for (auto areabutton : this->areabuttons_){

		if (areabutton->IsPushed(mouse_pos, this->POS_)){

			areabutton->CalcValue(this->area_);

			if (this->area_ < 0) this->area_ = 0;
			if (this->area_ > 2) this->area_ = 2;

		}

		areabutton->SetNowPush(false);

	}

	for (auto heightbutton : this->heightbuttons_){

		if (heightbutton->IsPushed(mouse_pos,this->POS_)){

			heightbutton->CalcValue(this->height_);

			if (this->height_ < 0.0f) this->height_ = 0.0f;
			if (this->height_ > 1.0f) this->height_ = 1.0f;

		}

		heightbutton->SetNowPush(false);

	}

	for (auto timingbutton : this->timingbuttons_){

		if (timingbutton->IsPushed(mouse_pos,this->POS_)){

			timingbutton->CalcValue(this->timing_);

			if (this->timing_ < 0) this->timing_ = 0;
			if (this->timing_ > 999999) this->timing_ = 999999;

		}

		timingbutton->SetNowPush(false);
	}

}