#pragma once

struct BPM_DATA{

	int timing;
	int bpm;

	BPM_DATA(int timing, int bpm){

		this->timing = timing;
		this->bpm = bpm;

	}

	bool operator==(const BPM_DATA& data){

		return (this->bpm == data.bpm && this->timing == data.timing);

	}

};