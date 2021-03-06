#pragma once
#include "../../ESGLib.h"
#include "../Manager/NoteManager.h"
#include <memory>

class AbstructMiddleLeft{

public:
	~AbstructMiddleLeft() = default;

	virtual void Draw(){

		this->ScreenReady();

		SpriteBatch.Begin();

		this->MyClassDraw();

		SpriteBatch.End();

		this->ScreenDraw();

	};

	virtual void ClickCheck(Vector2 mouse_pos) = 0;

	static void SetNoteManager(std::shared_ptr<NoteManager> notemana_ptr){

		AbstructMiddleLeft::notemana_ptr_ = notemana_ptr;

	}

protected:

	void ScreenReady(){
	
		GraphicsDevice.SetRenderTarget(this->screen_);
		GraphicsDevice.Clear(Color_White);
	
	};
	void ScreenDraw();

	virtual void MyClassDraw() = 0;//派生先で実装するそれ

	AbstructMiddleLeft():
	POS_(Vector3(0.0f,40.0f,0.0f)),
	SCREENSIZE_(Vector2(960.0f,280.0f)){
	
		if (this->screen_ == nullptr){

			this->screen_ = GraphicsDevice.CreateRenderTarget(960, 280, PixelFormat_RGBA8888, DepthFormat_Unknown);

		}

		font_ = GraphicsDevice.CreateDefaultFont();
	
	};

	const Vector3 POS_;
	const Vector2 SCREENSIZE_;

	FONT font_;

	static RENDERTARGET screen_;
	static std::shared_ptr<NoteManager> notemana_ptr_;

};