#pragma once
#include "../../ESGLib.h"
#include "../Note/AbstructNote.h"
#include "../BPM_DATA_STRUCT.h"
#include <vector>
#include <algorithm>
#include <memory>

class JukeBox;

class NoteManager{

public:

	NoteManager(std::shared_ptr<JukeBox> jukebox_ptr);
	~NoteManager();

	void Update();

	void DrawtoLayer(int layerid, float layerheight,float layerwidth,float layernotehit_x);
	void DrawtoPlayArea(int areaid, float areaheight, float areawidth,float areanotehit_x);

	void AddNote(int layerid, int areaid, float height, int timing);

	void DeleteNote(AbstructNote* deletenote){

		int layerid;
		int areaid;
		std::vector<AbstructNote*>::iterator a_itr;
		std::vector<AbstructNote*>::iterator ae_itr;
		std::vector<AbstructNote*>::iterator l_itr;
		std::vector<AbstructNote*>::iterator le_itr;

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
			
			delete deletenote;

	}

	void LongMakeNote(std::vector<AbstructNote*>& selectnotes);

	AbstructNote* LayerClickCheck(Vector2 mouse_pos, 
		int layerid, 
		float areaheight,
		float areawidth,
		float notehit_xpos, 
		Vector3 correctionpos = Vector3_Zero){
		return nullptr;
	};

	AbstructNote* PlayAreaClickCheck(Vector2 mouse_pos,
		int areaid,
		float areaheight,
		float areawidth, 
		float notehit_xpos,
		Vector3 correctionpos = Vector3_Zero);

	unsigned GetBpmDataCount(){ return this->bpmdatas_.size(); }
	void AddBpmData(BPM_DATA adddata){

		unsigned size = this->GetBpmDataCount();
		if (size == 0) {

			this->bpmdatas_.push_back(adddata);
			return;

		}

		auto itr = this->bpmdatas_.begin();
		auto e_itr = this->bpmdatas_.end();

		int inserttiming = adddata.timing;
		int checktiming;

		while (itr != e_itr){

			checktiming = itr->timing;
			if (inserttiming < checktiming){

				this->bpmdatas_.insert(itr, adddata);

			}

			itr++;

		}

		//‚±‚±‚Ü‚Å—ˆ‚½‚Æ‚«‚Íˆê”Ô’x‚¢
		this->bpmdatas_.push_back(adddata);

	}

	void RemeveData(BPM_DATA removedata){

		auto itr = this->bpmdatas_.begin();
		auto e_itr = this->bpmdatas_.end();

		itr = std::find(itr,e_itr,removedata);

		this->bpmdatas_.erase(itr);

	}

	bool IsDataAdded(BPM_DATA finddata){

		auto itr = this->bpmdatas_.begin();
		auto e_itr = this->bpmdatas_.end();

		itr = std::find(itr, e_itr, finddata);

		return (itr != e_itr);

	}

	void BpmDataDraw(Vector2 correctionpos = Vector2_Zero){

		Vector2 pos = Vector2_Zero;
		float height = 0.0f;

		if (this->bpmdatas_.size() == 0){

			SpriteBatch.DrawString(this->font_, correctionpos, Color(0, 0, 0),_T("PLEASE SET BPMDATA"));

		}

		for (auto data : this->bpmdatas_){

			pos = Vector2_Zero;
			pos.y = height;
			pos += correctionpos;

			SpriteBatch.DrawString(this->font_,pos,Color(0,0,0),_T("BPM: %d TIMING: %d"),data.bpm,data.timing);
			
			height += 20.0f;

		}

	}

	bool MusicScoreExport();
	bool MusicScoreImport();

private:

	void AddNote(AbstructNote* addnote);

	bool CanAddNote(std::vector<AbstructNote*>& notes, AbstructNote* addnote);
	void NowHeightDraw(float areaheight);

	typedef std::vector<std::vector<AbstructNote*>* > NoteArray;
	NoteArray allplayarea_;
	NoteArray alllayer_;

	std::shared_ptr<JukeBox> jukebox_ptr_;
	std::vector<BPM_DATA> bpmdatas_;

	LONG nowmouse_y_;
	LONG maxbottom_;
	SPRITE sprite_;
	RectWH lineuserect_;

	FONT font_;

};