#pragma once
#include "AbstructSortRoot.h"

class DeleteSortRoot : public AbstructSortRoot{

public:

	DeleteSortRoot() = default;
	~DeleteSortRoot() = default;

	virtual void SelectNote(AbstructNote* note){

		if (note->GetSelectFlag()){

			this->RemoveNote(note);

		}
		else{

			this->selectnotes_.push_back(note);
			note->SetSelectFlag(true);

		}

	}

	virtual void Draw(FONT font){

		SpriteBatch.DrawString(font, Vector2_Zero, Color(255, 255, 255), _T("NOWSELECT DELETE or HEIGHTUNITE MODE"));

	}

private:

};