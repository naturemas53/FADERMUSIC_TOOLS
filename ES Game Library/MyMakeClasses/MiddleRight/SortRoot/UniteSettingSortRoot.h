#include "AbstructSortRoot.h"

class UniteSettingSortRoot : public AbstructSortRoot{

public:
	UniteSettingSortRoot(){

		for (int i = 0; i < 3; i++){

			this->selectplayarea[i] = false;

		}

	};
	~UniteSettingSortRoot() = default;

	virtual void SelectNote(AbstructNote* note){

		if (note->GetSelectFlag()){

			this->selectplayarea[note->GetPlayArea()] = false;
			this->RemoveNote(note);

		}
		else{

			NoteType type = note->GetType();
			int areaid = note->GetPlayArea();

			if (type == SINGLENOTE && !(this->selectplayarea[areaid])){

				this->selectplayarea[areaid] = true;
				this->selectnotes_.push_back(note);
				note->SetSelectFlag(true);

			}

		}

	}
	virtual void Draw(FONT font){

		SpriteBatch.DrawString(font, Vector2_Zero, Color(255, 255, 255), _T("NOWSELECT UNITE MODE"));

		SpriteBatch.DrawString(font, Vector2(0.0f, 20.0f), Color(255, 255, 255), Vector2_One * 0.8f, Vector3_Zero, Vector3_Zero,
			_T("すみません、今現在LONGNOTEの調整はできません。"));
		SpriteBatch.DrawString(font, Vector2(0.0f, 40.0f), Color(255, 255, 255), Vector2_One * 0.8f, Vector3_Zero, Vector3_Zero,
			_T("LONGNOTEの調整は、お手数おかけしますが、"));
		SpriteBatch.DrawString(font, Vector2(0.0f, 60.0f), Color(255, 255, 255), Vector2_One * 0.8f, Vector3_Zero, Vector3_Zero,
			_T("一度消して、再生成する形でお願いしますm(__)m"));

		
		std::wstring str;
		for (int i = 0; i < 3;i++){

			SpriteBatch.DrawString(font, Vector2(0.0f + 100.0f * i, 140.0f), Color(255, 255, 255), Vector2_One * 0.8f, Vector3_Zero, Vector3_Zero,
				_T("PlayArea : %d"),i);

			if (this->selectplayarea[i]) str = _T("SELECTED");
			else str = _T("NONE SELECT");

			SpriteBatch.DrawString(font, Vector2(0.0f + 100.0f * i, 155.0f), Color(255, 255, 255), Vector2_One * 0.8f, Vector3_Zero, Vector3_Zero,
				str.c_str());

		}

		if (this->selectnotes_.size() != 0){

			auto itr = this->selectnotes_.end();
			itr--;
			float height = (*itr)->GetHeight();
			int timing = (*itr)->GetTiming();

			SpriteBatch.DrawString(font, Vector2(0.0f, 180.0f), Color(255, 255, 255), Vector2_One * 0.7f, Vector3_Zero, Vector3_Zero,
				_T("FINAL SELECT NOTE  HEIGHT: %3.1f%% TIMING : %d"), height, timing);

		}

	}

private:

	bool selectplayarea[3];

};