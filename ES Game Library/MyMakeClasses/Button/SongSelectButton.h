#pragma once
#include "AbstructButton.h"
#include "../JukeBox.h"

class SongSelectButton : public AbstructButton{

public:

	SongSelectButton(Vector3 pos,JukeBox* jukebox) :
	AbstructButton(pos, _T("SONGSELECT"), Vector2(192.0f, 40.0f)),
	jukebox_(jukebox)
	{};
	~SongSelectButton() = default;

	void SongSelect(){

		this->jukebox_->ChangeMusic();

	}

private:

	JukeBox* jukebox_;

};