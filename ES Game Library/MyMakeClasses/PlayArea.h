#pragma once
#include "../ESGLib.h"

class PlayArea{

public:

	PlayArea(Vector3 pos,int id):
	POS_(pos),
	SIZE_(Vector2(426.0f,360.0f)),
	ID_(id),
	screen_(GraphicsDevice.CreateRenderTarget(426, 360, PixelFormat_RGBA8888,DepthFormat_Unknown))
	{
		if (this->sp_ == nullptr) {

			this->sp_ = GraphicsDevice.CreateSpriteFromFile(_T("playarea.png"));

		}

		if (this->font_ == nullptr){

			this->font_ = GraphicsDevice.CreateDefaultFont();

		}

	};

	~PlayArea() = default;

	void ScreenDraw();
	void NoteDrawBegin(){

		GraphicsDevice.SetRenderTarget(this->screen_);
		GraphicsDevice.Clear(Color_CornflowerBlue);

		SpriteBatch.Begin();

	}

	void NoteDrawEnd(){

		SPRITE sp = this->sp_;
		FONT font = this->font_;

		SpriteBatch.Draw(*sp, Vector3_Zero, 1.0f);

		SpriteBatch.DrawString(font, Vector2_One * 3.0f, Color(0, 0, 0), Vector2_One * 1.0f, Vector3_Zero, Vector3_Zero, _T("PlayArea:%d"), this->ID_);

		SpriteBatch.End();

	}

	int GetId(){ return this->ID_; }

private:

	static SPRITE sp_;
	static FONT font_;

	const Vector3 POS_;
	const Vector2 SIZE_;
	const int ID_;

	RENDERTARGET screen_;

};