#include "BPMManager.h"
#include <algorithm>
#include <math.h>

BPMManager::BPMManager(){

	this->font_ = GraphicsDevice.CreateDefaultFont();
	this->snapcount_ = 1;

}

BPMManager::~BPMManager(){



}

void BPMManager::DataDraw(Vector2 correctionpos){

	Vector2 pos = Vector2_Zero;
	float height = 0.0f;

	if (this->bpmdatas_.size() == 0){

		SpriteBatch.DrawString(this->font_, correctionpos, Color(0, 0, 0), _T("PLEASE SET BPMDATA"));

	}

	for (auto data : this->bpmdatas_){

		pos = Vector2_Zero;
		pos.y = height;
		pos += correctionpos;

		SpriteBatch.DrawString(this->font_, pos, Color(0, 0, 0), _T("BPM: %d TIMING: %d"), data.bpm, data.timing);

		height += 20.0f;

	}

}

void BPMManager::AddData(BPM_DATA data){

	if (this->IsInData(data)){

		this->RemoveData(data);

		return;

	}

	auto itr = this->bpmdatas_.begin();
	auto e_itr = this->bpmdatas_.end();

	int inserttiming = data.timing;
	int checktiming;

	while (itr != e_itr){

		checktiming = itr->timing;

		if (inserttiming < checktiming){

			this->bpmdatas_.insert(itr,data);
			return;

		}

		itr++;

	}

	//‚±‚±‚Ü‚Å—ˆ‚½‚Æ‚«‚Íˆê”Ô’x‚¢
	this->bpmdatas_.push_back(data);
	
}

void BPMManager::RemoveData(BPM_DATA data){

	auto itr = this->bpmdatas_.begin();
	auto e_itr = this->bpmdatas_.end();

	itr = std::find(itr, e_itr, data);

	if (itr != e_itr){

		this->bpmdatas_.erase(itr);

	}

}

bool BPMManager::IsInData(BPM_DATA data){

	auto itr = this->bpmdatas_.begin();
	auto e_itr = this->bpmdatas_.end();

	itr = std::find(itr,e_itr,data);

	if (itr != e_itr){

		return true;

	}

	return false;

}

int BPMManager::TimingSnap(int timing){

	float notetiming = (float)timing;

	if (this->bpmdatas_.size() == 0) return timing;

	int bpmtiming = 0;
	float snaptime = this->SnapTimeCalcration(notetiming, &bpmtiming);

	if (snaptime <= 0) return timing;

	notetiming -= (float)bpmtiming;

	if (fmodf(notetiming,snaptime) == 0){
		return timing;
	}
	else{

		float snaptiming = notetiming - fmodf(notetiming, snaptime);

		int halfsnaptime = snaptime / 2;
		if (fmodf(notetiming, snaptime) < halfsnaptime){

			return (int)snaptiming + bpmtiming;

		}
		else{

			return (int)snaptiming + bpmtiming + (int)snaptime;

		}

	}

}

void BPMManager::TimingSnap(AbstructNote* note){

	note->SetTiming(this->TimingSnap(note->GetTiming()) );

}

bool BPMManager::IsNoteSnaped(AbstructNote* note){

	int notetiming = note->GetTiming();

	int bpmtiming = 0;
	//¬”‚Å‚ ‚Ü‚è‚Æ‚©Œ¾‚¢o‚·‚Æ‚«‚è‚ª‚È‚¢‚Ì‚Å®”‚É
	int snaptime = (int)this->SnapTimeCalcration(notetiming,&bpmtiming);

	if (snaptime <= 0) return false;

	notetiming -= bpmtiming;

	if (notetiming % snaptime == 0){

		return true;

	}

	return false;

}

void BPMManager::ChangeSnap(int changevalue){

	this->snapcount_ += changevalue;

	if (this->snapcount_ == 0){

		this->snapcount_ += changevalue;

	}

	if (this->snapcount_ > 8){ this->snapcount_ = 8; }
	if (this->snapcount_ < -128){ this->snapcount_ = -128; }

}

float BPMManager::SnapTimeCalcration(int timing, int* bpmstarttime){

	if (this->bpmdatas_.size() == 0) return 0;

	auto itr = this->bpmdatas_.begin();
	auto e_itr = this->bpmdatas_.end();

	while (itr != e_itr){

		if (itr->timing <= timing){

			break;

		}

		itr++;

	}

	if (bpmstarttime != nullptr){

		(*bpmstarttime) = itr->timing;

	}

	float snaprate;
	if (this->snapcount_ < 0){
		snaprate = 1.0f / (float)-this->snapcount_;
	}
	else{
		snaprate = 1.0f * (float)this->snapcount_;
	}

	//ƒ~ƒŠ•b—~‚µ‚¢‚Ì‚Å6–œ
	float beattime = (60000.0f / (float)itr->bpm);

	float snaptime = (beattime * snaprate);

	return snaptime;

}