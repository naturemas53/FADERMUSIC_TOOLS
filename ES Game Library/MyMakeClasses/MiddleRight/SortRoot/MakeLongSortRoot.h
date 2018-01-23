#include "AbstructSortRoot.h"

class MakeLongSortRoot : public AbstructSortRoot{

public:
	MakeLongSortRoot(){};

	virtual ~MakeLongSortRoot()  = default;

	virtual void SelectNote(AbstructNote* note){
	
		unsigned size = this->selectnotes_.size();

		if (note->GetSelectFlag()){

			this->RemoveNote(note);
			return;
		}

		if (size == 0){

			this->AddNote(note);

		}
		else{

			auto itr = this->selectnotes_.begin();

			int area = (*itr)->GetPlayArea();

			int selectarea = note->GetPlayArea();
			NoteType type = note->GetType();

			if ((area == selectarea) && type == SINGLENOTE){

				this->AddNote(note);

			}

		}
	
	}

	virtual void Draw(FONT font){

		SpriteBatch.DrawString(font, Vector2_Zero, Color(255, 255, 255), _T("NOWSELECT MAKELONG MODE"));

		unsigned size = this->selectnotes_.size();

		if (size != 0){

			auto itr = this->selectnotes_.begin();
			int area = (*itr)->GetPlayArea();
			int timing = (*itr)->GetTiming();
			

			SpriteBatch.DrawString(font, Vector2(0.0f,20.0f), Color(255, 255, 255),
				_T("NOW SELECT AREA : %d TIMING : %d"),area,timing);
		
		}
		else{
			
			SpriteBatch.DrawString(font, Vector2(0.0f, 20.0f), Color(255, 255, 255), _T("PLEASE SELECT FIRSTNOTE"));

		}

	}

private:

};