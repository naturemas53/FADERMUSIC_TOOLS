#pragma once
#include "AbstructSortRoot.h"

class LongBreakSortRoot : public AbstructSortRoot{

public:

	LongBreakSortRoot() = default;
	~LongBreakSortRoot() = default;

	virtual void SelectNote(AbstructNote* note){

		if (note->GetType() == LONGNOTE){

			if (note->GetSelectFlag()){

				this->RemoveNote(note);

			}
			else{

				note->SetSelectFlag(true);
				this->selectnotes_.push_back(note);

			}

		}

	};
	virtual void Draw(FONT font){
	
		SpriteBatch.DrawString(font, Vector2_Zero, Color(255, 255, 255), _T("NOWSELECT LONGBREAK MODE"));
	
	};

private:

};