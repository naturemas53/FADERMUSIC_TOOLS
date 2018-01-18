#pragma once
#include "AbstructButton.h"
#include "../JukeBox.h"
#include <memory>

class SongSelectButton : public AbstructButton{

public:

	SongSelectButton(Vector3 pos, std::shared_ptr<JukeBox> jukebox_ptr) :
	AbstructButton(pos, _T("SONGSELECT"), Vector2(192.0f, 40.0f)),
	jukebox_ptr_(jukebox_ptr)
	{};
	~SongSelectButton() = default;

	void SongSelect(){

		this->jukebox_ptr_->ChangeMusic();

	}

private:

	std::shared_ptr<JukeBox> jukebox_ptr_;

};