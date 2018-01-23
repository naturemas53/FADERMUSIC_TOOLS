#include "NoteManager.h"
#include "../Note/SingleNote.h"
#include "../Note/LongNote.h"
#include "../Note/PointNote.h"
#include "../JukeBox.h"
#include "../InputSingleton.h"
#include "../SpriteSingleton.h"
#include <algorithm>
#include <math.h>
#include <fstream>

NoteManager::NoteManager(std::shared_ptr<JukeBox> jukebox_ptr){

	this->jukebox_ptr_ = jukebox_ptr;

	for (int i = 0; i < 3; i++) this->allplayarea_.push_back(new std::vector<AbstructNote*>);
	for (int i = 0; i < 8; i++) this->alllayer_.push_back(new std::vector<AbstructNote*>);

	this->nowmouse_y_ = 0;
	this->maxbottom_ = 1000;

	this->sprite_ = StaticSprite.GetSprite();
	this->lineuserect_ = RectWH(192, 202, 320, 5);

	this->font_ = GraphicsDevice.CreateDefaultFont();

}

NoteManager::~NoteManager(){

	for (auto notearrays : this->allplayarea_){

		for (auto note : *(notearrays)){

			delete note;

		}

		delete notearrays;

	}

	for (auto notearrays : this->alllayer_) delete notearrays;

}

void NoteManager::Update(){


	this->nowmouse_y_ += StaticInput.GetMouseYMove();

	if (nowmouse_y_ < 0) nowmouse_y_ = 0;
	if (nowmouse_y_ > this->maxbottom_) nowmouse_y_ = this->maxbottom_;

	if (!(this->jukebox_ptr_->IsInMusic())) return;

	if (StaticInput.IsKeyPressed(Keys_S)){

		int playarea = 0;
		float height = (float)this->nowmouse_y_ / (float)this->maxbottom_;
		int timing = this->jukebox_ptr_->GetNowTimeMiliSec();

		this->AddNote(0, playarea, height, timing);

	}

	if (StaticInput.IsKeyPressed(Keys_D)){

		int playarea = 1;
		float height = (float)this->nowmouse_y_ / (float)this->maxbottom_;
		int timing = this->jukebox_ptr_->GetNowTimeMiliSec();

		this->AddNote(0, playarea, height, timing);

	}

	if (StaticInput.IsKeyPressed(Keys_F)){

		int playarea = 2;
		float height = (float)this->nowmouse_y_ / (float)this->maxbottom_;
		int timing = this->jukebox_ptr_->GetNowTimeMiliSec();

		this->AddNote(0, playarea, height, timing);

	}

}

void NoteManager::DrawtoLayer(int layerid, float layerheight, float layerwidth, float layernotehit_x){

	DWORD nowtime = this->jukebox_ptr_->GetNowTimeMiliSec();

	for (auto note : *(this->alllayer_[layerid])){

		if (labs((long)note->GetTiming() - nowtime) < 1000){

				note->LayerDraw(layerheight, layerwidth, layernotehit_x, nowtime);


		}
		else if ((long)note->GetTiming() > nowtime){

			break;

		}

	}

}

void NoteManager::DrawtoPlayArea(int areaid, float areaheight, float areawidth, float areanotehit_x){

	long nowtime = (long)this->jukebox_ptr_->GetNowTimeMiliSec();
	NoteType type;
	DWORD timing;

	DWORD mostslowtiming;
	LongNote* longnote;

	this->NowHeightDraw(areaheight);

	for (auto note : *(this->allplayarea_[areaid])){

		type = note->GetType();
		timing = note->GetTiming();


		if (type == SINGLENOTE){

			if (timing + 1000 < nowtime) continue;

			if (labs((long)timing - nowtime) < 1000){

				note->PlayAreaDraw(areaheight, areawidth, areanotehit_x, nowtime);

			}

		}
		else if (type == LONGNOTE){

			longnote = (LongNote*)note;
			mostslowtiming = longnote->GetMostSlowTiming();

			if ((long)timing - 1000 < nowtime || (long)mostslowtiming + 1000 > nowtime){

				longnote->PlayAreaDraw(areaheight, areawidth, areanotehit_x, nowtime);

			}
			

		}

	}

}

void NoteManager::AddNote(int layerid, int areaid, float height, int timing){

	if (timing < 0) timing = 0;
	if (timing > this->jukebox_ptr_->GetLengthMiliSec()) timing = this->jukebox_ptr_->GetLengthMiliSec();

		SingleNote* newnote = new SingleNote();
		newnote->SetLayer(layerid);
		newnote->SetPlayArea(areaid);
		newnote->SetHeight(height);
		newnote->SetTiming(timing);

		
		if (this->CanAddNote(*(this->allplayarea_[areaid]), newnote)){
		
			this->CanAddNote(*(this->alllayer_[layerid]), newnote);//�����͓���邾���@������Ȃ������炻��͂����
			return;
		}
		else{

			delete newnote;
			return;

		}

}

AbstructNote* NoteManager::PlayAreaClickCheck(Vector2 mouse_pos,
	int areaid,
	float areaheight,
	float areawidth,
	float notehit_xpos,
	Vector3 correctionpos){

	long nowtime = this->jukebox_ptr_->GetNowTimeMiliSec();
	long timing = 0;

	for(auto note : *(this->allplayarea_[areaid])){

		timing = (long)note->GetTiming();

		if (timing < nowtime - 1000) continue;
		if (timing > nowtime + 1000) break;

		if (note->PlayAreaClickCheck(mouse_pos, correctionpos, areaheight, areawidth, notehit_xpos, nowtime)){

			return note;

		}
	

	}

	//�����܂ŗ����Ƃ��͂ǂ̃m�[�g�ɂ�������Ȃ�����
	return nullptr;


}

bool NoteManager::CanAddNote(std::vector<AbstructNote*>& notes,AbstructNote* newnote){

	int checktiming = 0;
	int newtiming = newnote->GetTiming();

	if (notes.size() == 0){

		notes.push_back(newnote);
		return true;

	}
	else{

		auto itr = notes.begin();

		while (itr != notes.end())
		{

			checktiming = (*itr)->GetTiming();

			if (checktiming >= newtiming){

				if (checktiming == newtiming){

					return false;

				}
				else{

					notes.insert(itr, newnote);
					return true;

				}

			}

			itr++;
		}

		//�����܂ŗ����Ƃ��͑S�m�[�g�̒��Ń^�C�~���O����Ԓx������
		notes.push_back(newnote);
		return true;

	}

}

void NoteManager::LongMakeNote(std::vector<AbstructNote*>& selectnotes){

	auto itr = selectnotes.begin();
	auto e_itr = selectnotes.end();

	int layerid;
	int areaid;
	std::vector<AbstructNote*>::iterator a_itr;
	std::vector<AbstructNote*>::iterator ae_itr;
	std::vector<AbstructNote*>::iterator l_itr;
	std::vector<AbstructNote*>::iterator le_itr;

	AbstructNote* deletenote;

	while (itr != e_itr){
		
		deletenote = (*itr);

		layerid = deletenote->GetLayer();
		areaid = deletenote->GetPlayArea();

		a_itr = this->allplayarea_[areaid]->begin();
		ae_itr = this->allplayarea_[areaid]->end();
		a_itr = std::find(a_itr, ae_itr, deletenote);
		if (a_itr != ae_itr) this->allplayarea_[areaid]->erase(a_itr);

		l_itr = this->alllayer_[layerid]->begin();
		le_itr = this->alllayer_[layerid]->end();
		l_itr = std::find(l_itr, le_itr, deletenote);
		if (l_itr != le_itr) this->alllayer_[layerid]->erase(l_itr);	

		itr++;

	}

	itr = selectnotes.begin();

	LongNote* longnote = new LongNote((*itr));
	PointNote* pointnote;

	itr++;

	while (itr != e_itr){

		pointnote = new PointNote((*itr));
		longnote->AddPoint(pointnote);

		itr++;

	}

	//AbstructNote* addnote = (AbstructNote*)longnote;

	areaid = longnote->GetPlayArea();
	layerid = longnote->GetLayer();

	this->CanAddNote(*(this->allplayarea_[areaid]), longnote);
	this->CanAddNote(*(this->alllayer_[layerid]), longnote);

}

void NoteManager::NowHeightDraw(float areaheight){

	areaheight -= 30.0f; //�m�[�g�̑傫��

	float height = (float)this->nowmouse_y_ / (float)this->maxbottom_;
	float drawheight = (areaheight * height) + 15.0f; //�m�[�g�̑傫���̔���

	Vector3 pos = Vector3_Zero;
	pos.y = drawheight;

	Rect userect = this->lineuserect_;
	SPRITE sp = this->sprite_;

	SpriteBatch.Draw(*sp,pos,userect,1.0f);

}

bool NoteManager::MusicScoreExport(){

	//�܂��`�F�b�N
	unsigned size = this->bpmdatas_.size();
	if (size == 0) return false; //BPM�ݒ肵��
	
	unsigned areacount = this->allplayarea_.size();
	unsigned notezerocount = 0;

	for (auto notes : this->allplayarea_){

		size = notes->size();
		if (size == 0){
			notezerocount++;
		}

	}

	if (size == notezerocount) return false; //�m�[�g�ݒ肵��

	std::vector<AbstructNote*> notes;

	auto l_itr = this->allplayarea_[0]->begin();
	auto c_itr = this->allplayarea_[1]->begin();
	auto r_itr = this->allplayarea_[2]->begin();

	auto le_itr = this->allplayarea_[0]->end();
	auto ce_itr = this->allplayarea_[1]->end();
	auto re_itr = this->allplayarea_[2]->end();

	int l_timing;
	int c_timing;
	int r_timing;

	AbstructNote* innote;

	while (true){

		if (l_itr != le_itr){ l_timing = (*l_itr)->GetTiming(); }
		else{ l_timing = INT_MAX; }
		if (c_itr != ce_itr){ c_timing = (*c_itr)->GetTiming(); }
		else{ c_timing = INT_MAX; }
		if (r_itr != re_itr){ r_timing = (*r_itr)->GetTiming(); }
		else{ r_timing = INT_MAX; }

		if (l_timing < c_timing){

			if (l_timing < r_timing){

				innote = (*l_itr);
				l_itr++;

			}
			else{

				innote = (*r_itr);
				r_itr++;

			}

		}
		else if (c_timing < r_timing){

			innote = (*c_itr);
			c_itr++;

		}
		else{

			innote = (*r_itr);
			r_itr++;

		}

		notes.push_back(innote);

		if ((l_itr == le_itr) && (c_itr == ce_itr) && (r_itr == re_itr)) break;

	}

	wchar_t path[256] = {};

	OPENFILENAME ofn = {};
	ofn.hwndOwner = NULL;
	ofn.hInstance = NULL;
	ofn.lpstrFilter = _T("�e�L�X�g�f�[�^ (.txt)\0*.txt\0\0");
	ofn.nMaxFile = MAX_PATH;
	ofn.lpstrFileTitle = path;
	ofn.nMaxFileTitle = MAX_PATH;
	ofn.Flags = (OFN_OVERWRITEPROMPT | OFN_FILEMUSTEXIST | OFN_NONETWORKBUTTON);
	ofn.pvReserved = 0;
	ofn.dwReserved = 0;
	ofn.lStructSize = sizeof(ofn);

	if (GetSaveFileName(&ofn)){

		std::wstring wstr = path;

		if (wstr.size() != 0){

			std::ofstream file(wstr, std::ios::out);

			if (file){

				char str[256] = {};
				file << "BPM" << std::endl;

				for (auto data : this->bpmdatas_){
					memset(str,0,sizeof(str));
					
					sprintf_s(str, sizeof(str),"%06d %03d", data.timing, data.bpm);

					file << str << std::endl;

				}

				file << std::endl << "NOTES" << std::endl;

				NoteType type;

				int playarea;
				float height;
				int timing;

				std::vector<PointNote*> points;
				LongNote* longnote;

				auto itr = points.begin();
				auto e_itr = points.end();

				if (notes.size() == 0){

					int a = 191919419;

				}

				for (auto note : notes){

					memset(str, 0, sizeof(str));
					type = note->GetType();
					playarea = note->GetPlayArea();
					height = note->GetHeight();
					timing = note->GetTiming();

					if (type == SINGLENOTE){

						sprintf_s(str, sizeof(str), "%d %06d %.06f S",
							playarea,timing,height);

						file << str << std::endl;

					}
					else if (type == LONGNOTE){

						longnote = (LongNote*)note;

						points = longnote->GetPoints();

						itr = points.begin();
						e_itr = points.end();
						e_itr--;

						while (itr != points.end()){

							memset(str, 0, sizeof(str));
							playarea = (*itr)->GetPlayArea();
							height = (*itr)->GetHeight();
							timing = (*itr)->GetTiming();

							if (itr != e_itr){
								sprintf_s(str, sizeof(str), "%d %06d %.06f L",
									playarea, timing, height);
							}
							else{

								sprintf_s(str, sizeof(str), "%d %06d %.06f E",
									playarea, timing, height);

							}

							file << str << std::endl;

							itr++;
						}

					}

				}

			}
			else{

				return false; //�t�@�C��������

			}

		}
		else{

			return false;//�p�X�������ĂȂ�

		}

	}
	else{

		return false;//�Ȃ񂩂�������

	}

	return true;

}