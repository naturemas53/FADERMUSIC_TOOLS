#include "AbstructMiddleLeft.h"

RENDERTARGET AbstructMiddleLeft::screen_ = nullptr;
std::shared_ptr<NoteManager> AbstructMiddleLeft::notemana_ptr_ = nullptr;

void AbstructMiddleLeft::ScreenDraw(){

	GraphicsDevice.SetDefaultRenderTarget();

	SpriteBatch.Begin();

	Vector3 pos = this->POS_;
	RENDERTARGET sp = this->screen_;

	SpriteBatch.Draw(*sp,pos,1.0f);
	
	SpriteBatch.End();

}