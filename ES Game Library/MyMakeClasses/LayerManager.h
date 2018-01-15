#pragma once
#include "../ESGLib.h"
#include <vector>

class Layer;

class LayerManager{

public:

	LayerManager();
	~LayerManager();

	void Draw();
	void NoteDraw();
	
	void ClickCheck(Vector2 mouse_pos, Vector3 correctionpos = Vector3_Zero);

private:

	std::vector<Layer*> layers_;

};