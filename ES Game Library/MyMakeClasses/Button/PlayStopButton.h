#include "AbstructButton.h"
#include "../SpriteSingleton.h"

class PlayStopButton : public AbstructButton{

public:

	PlayStopButton() :
	AbstructButton(Vector3_Zero, _T(""), this->IMAGESIZE_){
	
		this->sp_ = StaticSprite.GetSprite();
	
	};
	~PlayStopButton() = default;

	virtual void Draw(){

		this->AbstructButton::Draw();

		SPRITE sp = this->sp_;
		Vector3 pos = Vector3_Zero;
		pos.x = (this->IMAGESIZE_.x - 30.0f) / 2.0f;
		pos.y += 5.0f;
		Rect userect;

		if (!(this->music_->IsPlaying())) userect = RectWH(120, 80, 30, 30);
		else userect = RectWH(150, 80, 30, 30);

		SpriteBatch.Draw(*sp, pos, userect, 1.0f);

	}

	void MusicStartStop(){

		if (this->music_->IsPlaying()) this->music_->Stop();
		else this->music_->Play();

	}

	void SetMusic(SOUND music){ this->music_ = music; }

private:

	SPRITE sp_;
	SOUND music_;

};