#include "AbstructSortRoot.h"

class SettingSortRoot : public AbstructSortRoot{

public:
	SettingSortRoot() = default;
	~SettingSortRoot() = default;

	virtual void SelectNote(AbstructNote* note){

		if (note->GetSelectFlag()){

			this->RemoveNote(note);
			return;

		}

		if (note->GetType() == SINGLENOTE){

			this->AddNote(note);

		}

	}
	virtual void Draw(FONT font){

		SpriteBatch.DrawString(font, Vector2_Zero, Color(255, 255, 255), _T("NOWSELECT SETTING MODE"));

		SpriteBatch.DrawString(font, Vector2(0.0f, 20.0f), Color(255, 255, 255), Vector2_One * 0.8f, Vector3_Zero, Vector3_Zero,
			_T("���݂܂���A������LONGNOTE�̒����͂ł��܂���B"));
		SpriteBatch.DrawString(font, Vector2(0.0f, 40.0f), Color(255, 255, 255), Vector2_One * 0.8f, Vector3_Zero, Vector3_Zero,
			_T("LONGNOTE�̒����́A���萔���������܂����A"));
		SpriteBatch.DrawString(font, Vector2(0.0f, 60.0f), Color(255, 255, 255),Vector2_One * 0.8f,Vector3_Zero,Vector3_Zero,
			_T("��x�����āA�Đ�������`�ł��肢���܂�m(__)m"));


	}

private:

};