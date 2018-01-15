#pragma once
#include "../../ESGLib.h"

class AbstructMiddleRight{

public:
	~AbstructMiddleRight() = default;

	void Draw(){

		this->ScreenReady();

		SpriteBatch.Begin();

		this->MyClassDraw();

		SpriteBatch.End();

		this->ScreenDraw();

	}

	virtual void ClickCheck(Vector2 mouse_pos) = 0;

protected:

	virtual void MyClassDraw() = 0;//�h����ɂ���ĕ`����e���Ⴄ�̂ł���

	void ScreenReady(){

		GraphicsDevice.SetRenderTarget(this->screen_);
		GraphicsDevice.Clear(Color_Green);

	}
	void ScreenDraw();

	AbstructMiddleRight() :
	POS_(Vector3(1280.0f - 320.0f,80.0f,0.0f)){

		if (this->screen_ == nullptr){

			this->screen_ = GraphicsDevice.CreateRenderTarget(320, 240, PixelFormat_RGBA8888, DepthFormat_Unknown);

		}

		if (this->font_ == nullptr){

			this->font_ = GraphicsDevice.CreateDefaultFont();

		}

	};

	const Vector3 POS_;
	static RENDERTARGET screen_;
	static FONT font_;

};