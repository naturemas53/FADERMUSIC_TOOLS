#pragma once
#include "../../ESGLib.h"
#include <vector>
#include <memory>

class Layer;
class NoteManager;
class JukeBox;

class LayerManager{

public:

	LayerManager(std::shared_ptr<NoteManager> notemana_ptr);
	~LayerManager();

	void Draw();
	void NoteDraw();
	
	void ClickCheck(Vector2 mouse_pos, Vector3 correctionpos = Vector3_Zero);

	static void SetJukeBox(std::shared_ptr<JukeBox> jukebox_ptr){

		LayerManager::jukebox_ptr_ = jukebox_ptr;

	}

private:

	std::vector<Layer*> layers_;
	std::shared_ptr<NoteManager> notemana_ptr_;

	static std::shared_ptr<JukeBox> jukebox_ptr_;

};