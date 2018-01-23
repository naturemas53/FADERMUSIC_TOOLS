#include "NoteManager.h"
#include "../Note/SingleNote.h"
#include "../Note/LongNote.h"
#include "../Note/PointNote.h"
#include "../JukeBox.h"
#include "../InputSingleton.h"
#include "../SpriteSingleton.h"
#include <algorithm>
#include <math.h>

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

		if (timing + 1000 < nowtime) continue;

		if (type == SINGLENOTE){

			if (labs((long)timing - nowtime) < 1000){

				note->PlayAreaDraw(areaheight, areawidth, areanotehit_x, nowtime);

			}

		}
		else if (type == LONGNOTE){

			longnote = (LongNote*)note;
			mostslowtiming = longnote->GetMostSlowTiming();

			if ((long)timing - 1000 < nowtime && (long)mostslowtiming + 1000 > nowtime){

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
		
			this->CanAddNote(*(this->alllayer_[layerid]), newnote);//こいつは入れるだけ　入れらんなかったらそれはそれで
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

	//ここまで来たときはどのノートにも当たらなかった
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

		//ここまで来たときは全ノートの中でタイミングが一番遅かった
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

	areaheight -= 30.0f; //ノートの大きさ

	float height = (float)this->nowmouse_y_ / (float)this->maxbottom_;
	float drawheight = (areaheight * height) + 15.0f; //ノートの大きさの半分

	Vector3 pos = Vector3_Zero;
	pos.y = drawheight;

	Rect userect = this->lineuserect_;
	SPRITE sp = this->sprite_;

	SpriteBatch.Draw(*sp,pos,userect,1.0f);

}