#pragma once
#include "../../ESGLib.h"
#include "../Note/AbstructNote.h"
#include "../BPM_DATA_STRUCT.h"
#include "BPMManager.h"
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

	void TimingUnite(int value,std::vector<AbstructNote*>& notes,AbstructNote* unitenote);
	void TimingChenge(int value,std::vector<AbstructNote*>& notes);

	void AddNote(int layerid, int areaid, float height, int timing);

	void DeleteNote(std::vector<AbstructNote*>& deletenotes){

		int layerid;
		int areaid;
		std::vector<AbstructNote*>::iterator a_itr;
		std::vector<AbstructNote*>::iterator ae_itr;
		std::vector<AbstructNote*>::iterator l_itr;
		std::vector<AbstructNote*>::iterator le_itr;

		auto itr = deletenotes.begin();
		auto e_itr = deletenotes.end();

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

			delete deletenote;
		
			itr++;

		}

	}

	void LongMakeNote(std::vector<AbstructNote*>& selectnotes);
	void LongBreakNote(std::vector<AbstructNote*>& breaknotes);

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

	int GetBpmDataCount(){ return this->bpmmanager_.GetDataSize(); }
	void AddBpmData(BPM_DATA adddata){

		this->bpmmanager_.AddData(adddata);

	}

	void BpmDataDraw(Vector2 correctionpos = Vector2_Zero){

		this->bpmmanager_.DataDraw(correctionpos);

	}

	void SnapFlagChenge(){

		if (this->snapflag_){

			this->snapflag_ = false;

		}
		else{

			if (this->bpmmanager_.GetDataSize() == 0) return;

			this->snapflag_ = true;

		}

	}

	void SnapCountChenge(int value){

		this->bpmmanager_.ChangeSnap(value);

	}

	bool GetSnapFlag(){ return this->snapflag_; }
	int GetSnapCount(){ return this->bpmmanager_.GetSnapCount(); }

	bool MusicScoreExport();
	bool MusicScoreImport();

private:

	void AddNote(AbstructNote* addnote);

	bool CanAddNote(std::vector<AbstructNote*>& notes, AbstructNote* addnote);
	void NowHeightDraw(float areaheight);

	typedef std::vector<std::vector<AbstructNote*>* > NoteArray;
	NoteArray allplayarea_;
	NoteArray alllayer_;

	BPMManager bpmmanager_;

	std::shared_ptr<JukeBox> jukebox_ptr_;

	LONG nowmouse_y_;
	LONG maxbottom_;
	SPRITE sprite_;
	RectWH lineuserect_;

	FONT font_;

	bool snapflag_;

};