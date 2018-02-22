#pragma once
#include "../ESGLib.h"

class PlayStopButton;

class JukeBox{

public:

	JukeBox();
	~JukeBox();

	void Update();
	void Draw(){

		this->ScreenReady();

		SpriteBatch.Begin();

		this->MyClassDraw();

		SpriteBatch.End();

		this->ScreenDraw();

	}
	

	void ChangeMusic();
	int GetElapsedTime(){};
	DWORD GetNowTimeMiliSec(){

		if (this->music_ == nullptr){

			return 0;

		}

		float playrate = (float) this->nowposbyte_ / (float)this->lengthbyte_;

		return (DWORD)((float) this->lengthtime_ * playrate);

	}

	DWORD GetLengthMiliSec(){

		if (this->music_ == nullptr){

			return 0;

		}

		return this->lengthtime_;

	}

	bool IsPlaying(){ return this->music_->IsPlaying(); }
	bool IsInMusic(){ return (this->music_ != nullptr); }

	void ClickCheck(Vector2 mouse_pos);


private:

	void ScreenReady(){

		GraphicsDevice.SetRenderTarget(this->screen_);
		GraphicsDevice.Clear(Color_LightBlue);

	}

	void MyClassDraw();

	void ScreenDraw(){

		GraphicsDevice.SetDefaultRenderTarget();

		SpriteBatch.Begin();

		RENDERTARGET screen = this->screen_;
		Vector3 pos = this->POS_;

		SpriteBatch.Draw(*screen, pos, 1.0f);

		SpriteBatch.End();

	}

	const Vector3 POS_;

	const float PLAYBARSIZE_;
	const Vector3 POINT_CORRECTIONPOS_;

	FONT font_;
	SPRITE sp_;
	RENDERTARGET screen_;
	PlayStopButton* button_;

	//MUSICå^ÇÃIDirectMusicLoader8ÇæÇ∆çƒê∂à íuÇ™åvéZÇµÇ∏ÇÁÇ¢ÇÃÇ≈
	//SOUNDå^ÇÃIDirectSoundBuffer8Ç…ÇµÇ‹ÇµÇΩ
	SOUND music_;
	int prevtime_;
	int lengthtime_;
	DWORD lengthbyte_;
	DWORD nowposbyte_;

	Vector3 pointpos_;
	bool pointhitflag_;
};