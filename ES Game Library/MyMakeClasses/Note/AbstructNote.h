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

	//�m�[�g�摜�̂ݕ`��
	void SimpleDraw(Vector3 drawcenter_pos);

	//�m�[�g�̃^�C�v�ɍ��킹�ĕ`��
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

	//�m�[�g�Ɋւ��Ă͕`��ʒu����܂�Ȃ����߁A
	//�Ăяo�����Ōv�Z���ăm�[�g�̈ʒu��n���Ă����Ȃ���΂����Ȃ�
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