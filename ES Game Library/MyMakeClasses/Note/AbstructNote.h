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

	//�m�[�g�摜�̂ݕ`��
	void SimpleDraw(float drawareaheight, float drawareawidth, float notehit_xpos, DWORD nowtime);

	//�m�[�g�̃^�C�v�ɍ��킹�ĕ`��
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


	//�l�X�ȏꏊ�ŕ`�悷�邽�߁A
	//�Ăяo�����ŕ␳�̈ʒu�icorrectionpos�j��n���Ă����邱�ƁB
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