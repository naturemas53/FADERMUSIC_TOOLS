#pragma once
#include "../../Note/AbstructNote.h"
#include <vector>
#include <algorithm>

enum SELECTMODE{

	SETTINGMODE,
	DOUBLEUNITEMODE,
	HEIGHTUNITEMODE,
	LONGMAKEMODE,
	LONGBREAKMODE,
	DELETEMODE

};

class AbstructSortRoot{

public:

	virtual ~AbstructSortRoot() = default;
	virtual void SelectNote(AbstructNote* note) = 0;
	virtual void Draw(FONT font) = 0;

	std::vector<AbstructNote*>& GetSelectNotes(){ return this->selectnotes_; }

protected:
	AbstructSortRoot() = default;

	void AddNote(AbstructNote* addnote){

		addnote->SetSelectFlag(true);

		auto itr = this->selectnotes_.begin();
		auto e_itr = this->selectnotes_.end();

		int inserttiming = addnote->GetTiming();
		int checktiming;

		while (itr != e_itr){

			checktiming = (*itr)->GetTiming();

			if (inserttiming < checktiming){

				this->selectnotes_.insert(itr,addnote);
				return;

			}

			itr++;
		}

		//‚±‚±‚Ü‚Å—ˆ‚½‚Æ‚«‚Íˆê”Ô’x‚¢
		this->selectnotes_.push_back(addnote);

	}

	void RemoveNote(AbstructNote* removenote){

		removenote->SetSelectFlag(false);

		auto itr = this->selectnotes_.begin();
		auto e_itr = this->selectnotes_.end();

		itr = std::find(itr,e_itr,removenote);

		if (itr != e_itr){
			this->selectnotes_.erase(itr);
		}

	}

	std::vector<AbstructNote*> selectnotes_;

};