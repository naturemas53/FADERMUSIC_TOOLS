#include "JukeBox.h"
#include "SpriteSingleton.h"
#include "InputSingleton.h"
#include "Button\PlayStopButton.h"
#include <string>

JukeBox::JukeBox() :
POS_(Vector3(0.0f,320.0f,0.0f)),
PLAYBARSIZE_(860.0f),
POINT_CORRECTIONPOS_(Vector3(195.0f,5.0f,0.0f)){

	this->sp_ = StaticSprite.GetSprite();
	this->font_ = GraphicsDevice.CreateDefaultFont();
	this->screen_ = GraphicsDevice.CreateRenderTarget(1280, 40, PixelFormat_RGBA8888, DepthFormat_Unknown);

	this->music_ = nullptr;
	
	this->prevtime_ = 0;
	this->lengthtime_ = 0;
	this->lengthbyte_ = 0;
	this->nowposbyte_ = 0;

	this->pointpos_ = Vector3_Zero;
	this->pointhitflag_ = false;

	this->button_ = new PlayStopButton();

}

JukeBox::~JukeBox(){

	delete this->button_;

}

void JukeBox::Update(){

	if (this->music_ != nullptr){
		this->nowposbyte_ = this->music_->GetNowPosByte();
		
		if (this->pointhitflag_){

			LONG mouse_xmove = StaticInput.GetMouseXMove();
			this->pointpos_.x += (float)mouse_xmove;

			if (this->pointpos_.x < 0.0f) this->pointpos_.x = 0.0f;
			if (this->pointpos_.x > this->PLAYBARSIZE_){
				this->pointpos_.x = PLAYBARSIZE_;
			}
			float playrate = this->pointpos_.x / this->PLAYBARSIZE_;
			DWORD playposbyte = (DWORD)(playrate * (float)this->lengthbyte_);

			this->music_->SetPlayPosByte(playposbyte);

		}
		else{
			this->pointpos_.x = this->PLAYBARSIZE_ * ((float)this->nowposbyte_ / (float)this->lengthbyte_);
		}

	}

}

void JukeBox::MyClassDraw(){

	//使いまわし　まずはライン
	Rect userect = RectWH(192,202,320,5);

	SPRITE sp = this->sp_;
	Vector3 pos = Vector3_Zero;
	pos.x = 210.0f;
	pos.y = 15.0f;

	FONT font = this->font_;

	SpriteBatch.Draw(*sp,pos,userect,1.0f,Vector3_Zero,Vector3_Zero,Vector2( this->PLAYBARSIZE_ / 320.0f ,1.0f));

	if (this->music_ == nullptr){

		
		SpriteBatch.DrawString(font, Vector2_Zero, Color(0, 0, 0), _T("NONE MUSIC"));
		SpriteBatch.DrawString(font, Vector2(1050.0f, 0.0f), Color(0, 0, 0), _T("PLEASE SELECT MUSICFILE"));

	}
	else{

		this->button_->Draw();

		DWORD length = this->lengthtime_;

		DWORD now = this->GetNowTimeMiliSec();

		userect = RectWH(120, 110, 30, 30);
		pos = this->pointpos_ + this->POINT_CORRECTIONPOS_;

		SpriteBatch.Draw(*sp, pos, userect, 1.0f);

		SpriteBatch.DrawString(font, Vector2(1100.0f, 10.0f), Color(0, 0, 0), _T("%02d:%02d.%03d / %02d:%02d.%03d"),
			now / 60000, (now / 1000) % 60, now % 1000,
			length / 60000,(length / 1000) % 60,length % 1000);
	}

}

void JukeBox::ChangeMusic(){

	if (this->music_ != nullptr){

		SoundDevice.ReleaseSound(this->music_);
		this->music_ = nullptr;

	}

	wchar_t str[256] = {};

	OPENFILENAMEW ofn = {};
	ofn.hwndOwner = NULL;
	ofn.hInstance = NULL;
	ofn.lpstrFilter = _T("楽曲 (.wav)\0*.wav\0\0");
	ofn.nMaxFile = MAX_PATH;
	ofn.lpstrFileTitle = str;
	ofn.nMaxFileTitle = MAX_PATH;
	ofn.Flags = (OFN_OVERWRITEPROMPT | OFN_FILEMUSTEXIST | OFN_NONETWORKBUTTON);
	ofn.pvReserved = 0;
	ofn.dwReserved = 0;
	ofn.lStructSize = sizeof(ofn);

	if (GetOpenFileNameW(&ofn)){

		std::wstring path = str;
		if (path.size() != 0){

			this->music_ = SoundDevice.CreateSoundFromFile(str);
			if (this->music_->IsNull()){

				this->music_ = nullptr;
				return;

			}
			this->button_->SetMusic(this->music_);
			this->lengthbyte_ = this->music_->GetLengthByte();
			DWORD secbyte = this->music_->Get1SecByte();

			float flength = (float)this->lengthbyte_ / (float)secbyte;
			this->lengthtime_ = (int)(flength * 1000);

			this->music_->Reset();
		}

	}

}

namespace{

	bool Collision(Vector3 pos_my,Vector2 size_my , Vector3 pos_t){

		if(pos_my.x > pos_t.x || pos_my.x + size_my.x < pos_t.x ||
			pos_my.y > pos_t.y || pos_my.y + size_my.y < pos_t.y){

			return false;

		}

		return true;

	}

}

void JukeBox::ClickCheck(Vector2 mouse_pos){

	//曲入ってないなら返す
	if (this->music_ == nullptr) return;

	if (StaticInput.IsMouseButtonPressed(Mouse_Button1)){
		Vector3 pointpos = this->POS_ + this->pointpos_ + this->POINT_CORRECTIONPOS_;
		Vector3 mousepos = Vector3(mouse_pos.x, mouse_pos.y, 0.0f);

		if (Collision(pointpos, Vector2(30.0f, 30.0f), mousepos)){

			this->pointhitflag_ = true;

		}

		if (this->button_->CollisionPointToMe(mouse_pos, this->POS_)){

			this->button_->MusicStartStop();

		}

	}
	else if (StaticInput.IsMouseButtonReleased(Mouse_Button1)){

		this->pointhitflag_ = false;

	}

}