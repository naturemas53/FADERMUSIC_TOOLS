#pragma once
#include "../../ESGLib.h"

enum NoteType{

	SINGLENOTE,
	LONGNOTE,
	POINTNOTE

};

class AbstructNote{

public:

	virtual ~AbstructNote() = default;

	//ノート画像のみ描画
	void LayerDraw(float drawareaheight, float drawareawidth, float notehit_xpos, DWORD nowtime);

	//ノートのタイプに合わせて描画
	virtual void PlayAreaDraw(float drawareaheight, float drawareawidth, float notehit_xpos, DWORD nowtime) = 0;

	void ValueCopy(AbstructNote* opponentnote){

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
	bool GetSelectFlag(){ return this->selectflag_; }
	Vector3 GetPlayAreaPos(float drawareaheight, float drawareawidth, float notehit_xpos, DWORD nowtime){ 
		return this->CalcPos(drawareaheight,drawareawidth,notehit_xpos,nowtime); 
	}
	AbstructNote* GetMe(){ return this; }

	void SetLayer(int layer){ this->layer_ = layer; }
	void SetPlayArea(int playarea){ this->playarea_ = playarea; }
	void SetHeight(float height){ 
		
		if (height < 0.0f) height = 0.0f;
		if (height > 1.0f) height = 1.0f;

		this->height_ = height; }
	void SetTiming(int timing){ 
		
		if (timing < 0) timing = 0;
		if (timing > 999999) timing = 999999;
		
		this->timing_ = timing; }
	void SetClapFlag(bool flag){ this->clapflag_ = flag; }
	void SetSelectFlag(bool flag){ this->selectflag_ = flag; }


	//様々な場所で描画するため、
	//呼び出す側で補正の位置（correctionpos）を渡してあげること。
	bool PlayAreaClickCheck(
		Vector2 mouse_pos, 
		Vector3 correctionpos,
		float drawareaheight,
		float drawareawidth,
		float notehit_xpos,
		DWORD nowtime);

	bool LayerClickCheck(
		Vector2 mouse_pos,
		Vector3 correctionpos,
		float drawareaheight,
		float drawareawidth,
		float notehit_xpos,
		DWORD nowtime);

protected:

	Vector3 CalcPos(float drawareaheight, float drawareawidth, float notehit_xpos, DWORD nowtime);
	AbstructNote(RectWH userect, NoteType type);

	static SPRITE sp_;

	const RectWH USERECT_;
	const RectWH MARKUSERECT_;
	const NoteType TYPE_;
	const Vector2 SIZE_;

	int layer_;
	int playarea_;
	float height_;
	int timing_;

	bool clapflag_;
	bool selectflag_;

};