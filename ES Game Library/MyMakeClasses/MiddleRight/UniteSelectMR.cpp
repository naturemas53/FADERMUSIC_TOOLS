#include "UniteSelectMR.h"
#include "SelectMR.h"
#include "MenuMR.h"

UniteSelectMR::UniteSelectMR(){

	Vector2 size = this->SCREENSIZE_;

	this->heightbutton_ = new FreeButton(Vector3(0.0f,40.0f,0.0f), _T("HEIGHT"));
	this->doubleunitebutton_ = new FreeButton(Vector3(0.0f, 80.0f, 0.0f), _T("HEIGHT & TIMING"));
	this->backbutton_ = new FreeButton(Vector3(0.0f, (size.y - 40.0f), 0.0f), _T("<- BACK"));


}

UniteSelectMR::~UniteSelectMR(){

	delete this->doubleunitebutton_;
	delete this->heightbutton_;
	delete this->backbutton_;

}

void UniteSelectMR::ClickCheck(Vector2 mouse_pos){

	if (this->heightbutton_->CollisionPointToMe(mouse_pos, this->POS_)){

		this->nextmr_ = new SelectMR(HEIGHTUNITEMODE);

	}

	if (this->doubleunitebutton_->CollisionPointToMe(mouse_pos, this->POS_)){

		this->nextmr_ = new SelectMR(DOUBLEUNITEMODE);

	}

	if (this->backbutton_->CollisionPointToMe(mouse_pos, this->POS_)){

		this->nextmr_ = new MenuMR();

	}

}

void UniteSelectMR::MyClassDraw(){

	this->doubleunitebutton_->Draw();
	this->heightbutton_->Draw();
	this->backbutton_->Draw();

}