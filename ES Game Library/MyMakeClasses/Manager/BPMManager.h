#pragma once
#include "../../ESGLib.h"
#include "../BPM_DATA_STRUCT.h"
#include "../Note\AbstructNote.h"
#include <vector>

class BPMManager{

public:

	BPMManager();
	~BPMManager();

	void DataDraw(Vector2 correctionpos = Vector2_Zero);

	void AddData(BPM_DATA data);
	void RemoveData(BPM_DATA data);
	bool IsInData(BPM_DATA data);

	void ChangeSnap(int changevalue);

	int TimingSnap(int timing);
	void TimingSnap(AbstructNote* note);
	bool IsNoteSnaped(AbstructNote* note);

	void DataClear(){ this->bpmdatas_.clear(); }

	int GetSnapTime(int timing){ return this->SnapTimeCalcration(timing); }
	int GetSnapCount(){ return this->snapcount_; }
	int GetDataSize(){ return (int)this->bpmdatas_.size(); }

	std::vector<BPM_DATA>& GetBpmDatas(){ return this->bpmdatas_; }

private:

	float SnapTimeCalcration(int timing,int* bpmstarttime = nullptr);

	int snapcount_;
	std::vector<BPM_DATA> bpmdatas_;

	FONT font_;

};