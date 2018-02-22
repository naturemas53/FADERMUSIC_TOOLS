#include "MenuMR.h"
#include "../Button/FreeButton.h"
#include "../InputSingleton.h"
#include "SelectMR.h"
#include "UniteSelectMR.h"

MenuMR::MenuMR(){

	this->buttons_["SETTING"] = new FreeButton(Vector3(0.0f,20.0f,0.0f),_T("SETTING"));
	this->buttons_["UNITE"] = new FreeButton(Vector3(0.0f, 60.0f, 0.0f), _T("UNITE"));
	this->buttons_["LONGMAKE"] = new FreeButton(Vector3(0.0f, 100.0f, 0.0f), _T("LONGMAKE"));
	this->buttons_["LONGBREAK"] = new FreeButton(Vector3(0.0f, 140.0f, 0.0f), _T("LONGBREAK"));
	this->buttons_["DELETE"] = new FreeButton(Vector3(0.0f, 180.0f, 0.0f), _T("DELETE"));

}

MenuMR::~MenuMR(){

	for (auto button : this->buttons_) delete button.second;

}

void MenuMR::MyClassDraw(){

	FONT font = this->font_;

	SpriteBatch.DrawString(font,Vector2_Zero,Color(255,255,255),_T(" NORMALNOTEMENU "));

	for (auto button : this->buttons_) button.second->Draw();

}

void MenuMR::ClickCheck(Vector2 mouse_pos){

	if (StaticInput.IsMouseButtonPressed(Mouse_Button1)){

		for (auto button : this->buttons_){

			if (button.second->CollisionPointToMe(mouse_pos,this->POS_)){

				this->SetNextMR(button.first);
				break;
			}

		}

	}

}

void MenuMR::SetNextMR(const std::string& mapkey_){

	if (mapkey_ == "SETTING"){

		this->nextmr_ = new SelectMR(SETTINGMODE);

	}
	else if (mapkey_ == "UNITE"){ 

		this->nextmr_ = new UniteSelectMR();

	}
	else if (mapkey_ == "LONGMAKE"){

		this->nextmr_ = new SelectMR(LONGMAKEMODE);

	}
	else if (mapkey_ == "LONGBREAK"){

		this->nextmr_ = new SelectMR(LONGBREAKMODE);

	}
	else if (mapkey_ == "DELETE"){

		this->nextmr_ = new SelectMR(DELETEMODE);

	}

}