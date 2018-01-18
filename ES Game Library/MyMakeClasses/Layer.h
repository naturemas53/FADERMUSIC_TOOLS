#pragma once
#include "../ESGLib.h"
#include "SpriteSingleton.h"

class Layer{

public:

	Layer(Vector3 pos,int id):
	POS_(pos),
	SIZE_(Vector2(480.0f,70.0f)),
	NOTEHITPOS_(150.0f),
	PANELUSERECT_(RectWH(0,80,120,70)),
	SPEAKERUSERECT_(RectWH(0,150,64,64)),
	ID_(id){
	
		if (sp_ == nullptr){

			this->sp_ = GraphicsDevice.CreateSpriteFromFile(_T("layer.png"));

		}

		if (l_panelsp_ == nullptr){

			this->l_panelsp_ = StaticSprite.GetSprite();

		}

		if (font_ == nullptr){

			this->font_ = GraphicsDevice.CreateDefaultFont();

		}

		this->screen_ = GraphicsDevice.CreateRenderTarget(480, 70, PixelFormat_RGBA8888, DepthFormat_Unknown);
		this->soundflag_ = true;

	}

	~Layer() = default;

	void NoteDrawBegin();
	//void NoteDraw();
	void NoteDrawEnd();

	void ScreenDraw();

	bool SpeakerClickCheck(Vector2 mouse_pos, Vector3 correctionpos = Vector3_Zero){

		Vector3 pos = this->POS_;
		pos.x += 5.0f;
		pos.y += 5.0f;
		pos += correctionpos;

		//64　は　スピーカーアイコンのサイズ

		if (pos.x > mouse_pos.x || pos.x + 64.0f < mouse_pos.x ||
			pos.y > mouse_pos.y || pos.y + 64.0f < mouse_pos.y){

			return false;

		}
	
		return true;

	};

	void ChengeSoundFlag(){ this->soundflag_ = !(this->soundflag_); }

	int GetId(){ return this->ID_; }
	float GetNoteHitPos(){ return this->NOTEHITPOS_; }
	Vector2 GetSize(){ return this->SIZE_; }

private:

	static SPRITE sp_;
	static SPRITE l_panelsp_;
	static FONT font_;

	const Vector3 POS_;
	const Vector2 SIZE_;
	const float NOTEHITPOS_;
	const RectWH PANELUSERECT_;
	const RectWH SPEAKERUSERECT_;
	const int ID_;

	RENDERTARGET screen_;
	bool soundflag_;

};