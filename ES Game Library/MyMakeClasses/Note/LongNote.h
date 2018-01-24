#include "AbstructNote.h"
#include "PointNote.h"
#include <vector>
#include <algorithm>

class LongNote : public AbstructNote{

public:

	LongNote(AbstructNote* addnote):
		AbstructNote(RectWH(222, 160, 30, 30), LONGNOTE){

		this->ValueCopy(addnote);

		PointNote* add = new PointNote(addnote);
		this->points_.push_back(add);

	}
	~LongNote(){
	
		for (auto point : this->points_) delete point;
	
	};

	virtual void PlayAreaDraw(float drawareaheight, float drawareawidth, float notehit_xpos, DWORD nowtime);

	int GetMostSlowTiming(){

		if (this->points_.size() == 0){

			return this->timing_;
			

		}

		auto e_itr = this->points_.end();
		e_itr--;

		return (*e_itr)->GetTiming();

	}

	std::vector<PointNote*>& GetPoints(){ return this->points_; }

	void AddPoint(PointNote* addpoint){

		auto itr = this->points_.begin();
		auto e_itr = this->points_.end();

		if (this->points_.size() == 0){

			this->points_.push_back(addpoint);
			return;

		}

		int inserttiming = addpoint->GetTiming();
		int checktiming;

		while (itr != e_itr){

			checktiming = (*itr)->GetTiming();

			if (checktiming > inserttiming){

				this->points_.insert(itr,addpoint);
				return;

			}

			itr++;

		}

		//‚±‚±‚Ü‚Å—ˆ‚½‚Æ‚«‚Íˆê”Ô’x‚¢

		this->points_.push_back(addpoint);


	}

	void RemovePoint(PointNote* addpoint){

		auto itr = this->points_.begin();
		auto e_itr = this->points_.end();

		itr = std::find(itr,e_itr,addpoint);

		if (itr != e_itr){

			this->points_.erase(itr);

		}

	}

private:

	std::vector<PointNote*> points_;

};