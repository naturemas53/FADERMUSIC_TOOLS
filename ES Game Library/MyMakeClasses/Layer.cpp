#include "Layer.h"

SPRITE Layer::sp_ = nullptr;
SPRITE Layer::l_panelsp_ = nullptr;
FONT Layer::font_ = nullptr;

void Layer::NoteDrawBegin(){

	GraphicsDevice.SetRenderTarget(this->screen_);
	GraphicsDevice.Clear(Color_White);

	SpriteBatch.Begin();

	SPRITE sp = this->sp_;

	SpriteBatch.Draw(*sp, Vector3_Zero, 1.0f);

}

void Layer::NoteDrawEnd(){

	SPRITE l_panelsp_ = this->l_panelsp_;
	Rect paneluserect = this->PANELUSERECT_;
	Rect speakeruserect = this->SPEAKERUSERECT_;
	FONT font = this->font_;

	float alpha = (this->soundflag_) ? 1.0f : 0.8f;

	GraphicsDevice.SetSamplerState(0, D3DSAMP_MAGFILTER, D3DTEXF_POINT);

	SpriteBatch.Draw(*l_panelsp_, Vector3_Zero, paneluserect, 1.0f);
	SpriteBatch.Draw(*l_panelsp_, Vector3(5.0f, 5.0f, 0.0f), speakeruserect, alpha);
	SpriteBatch.DrawString(font,Vector2(73.0,0.0f),Color(0,0,0),Vector2_One * 4.0f,Vector3_Zero,Vector3_Zero,_T("%d"),this->ID_);

	SpriteBatch.End();

}

void Layer::ScreenDraw(){

	RENDERTARGET screen = this->screen_;
	Vector3 pos = this->POS_;
	SpriteBatch.Draw(*screen, pos, 1.0f);

}