#pragma once
#include "../../ESGLib.h"
#include "../Manager/NoteManager.h"
#include <memory>

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

	static void SetNoteManager(std::shared_ptr<NoteManager> notemana_ptr){

		AbstructMiddleRight::notemana_ptr_ = notemana_ptr;
		 
	}

	AbstructMiddleRight* GetNextMR(){

		return this->nextmr_;

	}

protected:

	virtual void MyClassDraw() = 0;//”h¶æ‚É‚æ‚Á‚Ä•`‰æ“à—e‚ªˆá‚¤‚Ì‚Å‚»‚ê

	void ScreenReady(){

		GraphicsDevice.SetRenderTarget(this->screen_);
		GraphicsDevice.Clear(Color_Green);

	}
	void ScreenDraw();

	AbstructMiddleRight() :
	POS_(Vector3(1280.0f - 320.0f,80.0f,0.0f)),
	SCREENSIZE_(Vector2(320.0f,240.0f)){

		if (this->screen_ == nullptr){

			Vector2 size = this->SCREENSIZE_;

			this->screen_ = GraphicsDevice.CreateRenderTarget(size.x, size.y, PixelFormat_RGBA8888, DepthFormat_Unknown);

		}

		if (this->font_ == nullptr){

			this->font_ = GraphicsDevice.CreateDefaultFont();

		}

		nextmr_ = nullptr;

	};

	const Vector3 POS_;
	const Vector2 SCREENSIZE_;
	static RENDERTARGET screen_;
	static FONT font_;
	static std::shared_ptr<NoteManager> notemana_ptr_;

	AbstructMiddleRight* nextmr_;

};