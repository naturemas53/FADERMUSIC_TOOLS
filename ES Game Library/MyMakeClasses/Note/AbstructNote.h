#pragma once
#include "../../ESGLib.h"

enum NoteType{

	SINGLENOTE,
	LONGNOTE,
	POINTNOTE

};

class AbstructNote{

public:

	AbstructNote(RectWH userect,NoteType type);
	virtual ~AbstructNote() = default;

	//ノート画像のみ描画
	void SimpleDraw(float drawareaheight, float drawareawidth, float notehit_xpos, DWORD nowtime);

	//ノートのタイプに合わせて描画
	virtual void NormalDraw(float drawareaheight, float drawareawidth, float notehit_xpos, DWORD nowtime) = 0;

	void operator=(AbstructNote* opponentnote){

		this->SetLayer(opponentnote->GetLayer());
		this->SetPlayArea(opponentnote->GetPlayArea());
		this->SetHeight(opponentnote->GetHeight());
		this->SetTiming(opponentnote->GetTiming());

	}

	int GetLayer(){ return this->layer_; }
	int GetPlayArea(){ return this->playarea_; }
	float GetHeight(){ return this->height_; }
	int GetTiming(){ return this->timing_; }
	NoteType GetType(){ return this->TYPE_; }
	virtual AbstructNote* GetMe() = 0;

	void SetLayer(int layer){ this->layer_ = layer; }
	void SetPlayArea(int playarea){ this->playarea_ = playarea; }
	void SetHeight(float height){ this->height_ = height; }
	void SetTiming(int timing){ this->timing_ = timing; }
	void SetClapFlag(bool flag){ this->clapflag_ = flag; }


	//様々な場所で描画するため、
	//呼び出す側で補正の位置（correctionpos）を渡してあげること。
	virtual bool ClickCheck(Vector2 mouse_pos, Vector3 collectionpos, float drawareaheight, float drawareawidth, float notehit_xpos, DWORD nowtime) = 0;

	bool SimpleClickCheck(Vector2 mouse_pos, Vector3 collectionpos, float drawareaheight, float drawareawidth, float notehit_xpos, DWORD nowtime){

		return false;

	}

protected:

	static SPRITE sp_;

	const RectWH USERECT_;
	const NoteType TYPE_;
	const Vector2 SIZE_;

	int layer_;
	int playarea_;
	float height_;
	int timing_;

	bool clapflag_;

};