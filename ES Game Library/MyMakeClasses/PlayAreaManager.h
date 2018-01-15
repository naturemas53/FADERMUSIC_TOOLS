#pragma once
#include "../ESGLib.h"
#include <vector>

class PlayArea;

class PlayAreaManager{

public:

	PlayAreaManager();
	~PlayAreaManager();

	void Draw();

private:

	std::vector<PlayArea*> playareas_;

};