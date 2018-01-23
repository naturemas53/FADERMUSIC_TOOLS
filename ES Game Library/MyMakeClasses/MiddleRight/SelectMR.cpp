#include "SelectMR.h"
#include "../Manager/PlayAreaManager.h"
#include "SortRoot\DeleteSortRoot.h"
#include "SortRoot\MakeLongSortRoot.h"
#include "SortRoot\SettingSortRoot.h"
#include "SortRoot\UniteSettingSortRoot.h"
#include "../Button/FreeButton.h"
#include "../InputSingleton.h"
#include "MenuMR.h"
#include "SettingMR.h"
#include <algorithm>

std::shared_ptr<PlayAreaManager> SelectMR::areamana_ptr_ = nullptr;

SelectMR::SelectMR(SELECTMODE selectmode){

	switch (selectmode){

	case SETTINGMODE:
		
		this->sortroot_ = new SettingSortRoot();

		break;

	case UNITEMODE:

		this->sortroot_ = new UniteSettingSortRoot();

		break;

	case LONGMAKEMODE:

		this->sortroot_ = new MakeLongSortRoot();

		break;

	case DELETEMODE:

		this->sortroot_ = new DeleteSortRoot();

		break;

	default:

		this->sortroot_ = nullptr;

		break;

	}

	this->selectmode_ = selectmode;

	Vector2 size = this->SCREENSIZE_;

	Vector3 desidepos = Vector3_Zero;
	desidepos.x = (size.x - 192.0f) / 2.0f;
	desidepos.y = (size.y - 40.0f) / 2.0f;

	this->buttons_["DESIDE"] = new FreeButton(desidepos, _T("DESIDE"));
	this->buttons_["BACK"] = new FreeButton(Vector3(0.0f,(size.y - 40.0f), 0.0f), _T("<- BACK"));

}

SelectMR::~SelectMR(){

	delete this->sortroot_;
	for (auto button : this->buttons_) delete button.second;

}

void SelectMR::ClickCheck(Vector2 mouse_pos){

	if (!StaticInput.IsMouseButtonPressed(Mouse_Button1)) return;

	for (auto button : this->buttons_){

		if (button.second->CollisionPointToMe(mouse_pos,this->POS_)){
		
			this->CheckButton(button);
			return;

		}

	}

	if (this->sortroot_ == nullptr) return;

	AbstructNote* selectnote = this->areamana_ptr_->ClickCheck(mouse_pos);

	if (selectnote != nullptr){ this->sortroot_->SelectNote(selectnote); }

}

void SelectMR::MyClassDraw(){

	FONT font = this->font_;

	this->sortroot_->Draw(font);

	for (auto button : this->buttons_) button.second->Draw();

}

void SelectMR::CheckButton(std::pair<std::string, AbstructButton*> button){

	std::vector<AbstructNote*> notes = this->sortroot_->GetSelectNotes();

	if (button.first == "DESIDE"){

		if (notes.size() == 0) return;

		switch (this->selectmode_){

		case SETTINGMODE:

			this->nextmr_ = new SettingMR(false,notes);

			break;

		case UNITEMODE:

			this->nextmr_ = new SettingMR(true, notes);

			break;

		case LONGMAKEMODE:

			this->notemana_ptr_->LongMakeNote(notes);
			this->nextmr_ = new MenuMR();

			break;

		case DELETEMODE:

			for (auto note : notes){

				this->notemana_ptr_->DeleteNote(note);

			}

			this->nextmr_ = new MenuMR();
			break;

		default:

			this->nextmr_ = nullptr;

			break;

		}
		return;

	}
	else if (button.first == "BACK"){

		for (auto note : notes) note->SetSelectFlag(false);
		this->nextmr_ = new MenuMR();
		return;

	}

		this->nextmr_ = nullptr;
		return;

}