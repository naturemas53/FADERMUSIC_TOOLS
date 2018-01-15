#pragma once
#include "../../ESGLib.h"

enum NoteType{

	SINGLE,
	LONG,
	POINT

};

class AbstructNote{

public:

	AbstructNote(RectWH userect,NoteType type);
	~AbstructNote() = default;

	//ノート画像のみ描画
	void SimpleDraw(Vector3 drawcenter_pos);

	//ノートのタイプに合わせて描画
	virtual void NormalDraw(Vector3 drawcenter_pos);

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

	void SetLayer(int layer){ this->layer_ = layer; }
	void SetPlayArea(int playarea){ this->playarea_ = playarea; }
	void SetHeight(float height){ this->height_ = height; }
	void SetTiming(int timing){ this->timing_ = timing; }

	//ノートに関しては描画位置が定まらないため、
	//呼び出す側で計算してノートの位置を渡してあげなければいけない
	virtual bool ClickCheck(Vector2 mouse_pos, Vector3 drawcenter_pos) = 0;

private:

	static SPRITE sp_;

	const RectWH USERECT_;
	const NoteType TYPE_;

	int layer_;
	int playarea_;
	float height_;
	int timing_;

};