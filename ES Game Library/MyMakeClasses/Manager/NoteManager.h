#pragma once
#include "../../ESGLib.h"
#include "../Note/SingleNote.h"
#include <vector>
#include <memory>

class JukeBox;

class NoteManager{

public:

	NoteManager(std::shared_ptr<JukeBox> jukebox_ptr);
	~NoteManager();

	void DrawtoLayer(int layerid, float layerheight,float layerwidth,float layernotehit_x);
	void DrawtoPlayArea(int areaid, float areaheight, float areawidth,float areanotehit_x);

	void SettingNote(int layerid,int areaid,float height,int timing){

		unsigned selectcount = this->serectnotes_.size();

		if (selectcount == 0){

			SingleNote* newnote = new SingleNote();
			newnote->SetLayer(layerid);
			newnote->SetPlayArea(areaid);
			newnote->SetHeight(height);
			newnote->SetTiming(timing);

			this->AddNote(newnote);

		}
		else if (selectcount == 1){



		}
		else{


		}

	}

private:

	void AddNote(AbstructNote* addnote){

		this->notes_.push_back(addnote);

	}

	std::vector<AbstructNote*> notes_;
	std::vector<AbstructNote*> serectnotes_;
	std::shared_ptr<JukeBox> jukebox_ptr_;

};