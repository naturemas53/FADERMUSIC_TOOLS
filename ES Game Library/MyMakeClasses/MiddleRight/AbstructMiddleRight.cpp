#include "AbstructMiddleRight.h"

RENDERTARGET AbstructMiddleRight::screen_ = nullptr;
FONT AbstructMiddleRight::font_ = nullptr;

void AbstructMiddleRight::ScreenDraw(){

	GraphicsDevice.SetDefaultRenderTarget();

	SpriteBatch.Begin();

	Vector3 pos = this->POS_;
	RENDERTARGET sp = this->screen_;

	SpriteBatch.Draw(*sp, pos, 1.0f);

	SpriteBatch.End();

}