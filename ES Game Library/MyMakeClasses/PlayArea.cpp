#include "PlayArea.h"

SPRITE PlayArea::sp_ = nullptr;
FONT PlayArea::font_ = nullptr;

void PlayArea::ScreenDraw(){

	GraphicsDevice.SetDefaultRenderTarget();

	SpriteBatch.Begin();

	RENDERTARGET screen = this->screen_;
	Vector3 pos = this->POS_;

	SpriteBatch.Draw(*screen,pos,1.0f);

	SpriteBatch.End();

}