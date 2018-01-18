#include "LayerManager.h"
#include "NoteManager.h"
#include "../Layer.h"
#include "../JukeBox.h"

std::shared_ptr<JukeBox> LayerManager::jukebox_ptr_ = nullptr;

LayerManager::LayerManager(std::shared_ptr<NoteManager> notemana_ptr){

	for (int i = 0; i < 8; i++){

		this->layers_.push_back(new Layer(Vector3( (i / 4)* 480.0f,(i % 4) * 70.0f,0.0f),i));

	}

	this->notemana_ptr_ = notemana_ptr;

}

LayerManager::~LayerManager(){

	for (auto layer : this->layers_) delete layer;

}

void LayerManager::Draw(){

	for (auto layer : this->layers_) layer->ScreenDraw();

}

void LayerManager::NoteDraw(){

	Vector2 size;

	for (auto layer : this->layers_){

		layer->NoteDrawBegin();
		
		size = layer->GetSize();
		(this->notemana_ptr_)->DrawtoLayer(layer->GetId(), size.y, size.x, layer->GetNoteHitPos());

		layer->NoteDrawEnd();

	}

}

void LayerManager::ClickCheck(Vector2 mouse_pos, Vector3 correctionpos){

	for (auto layer : this->layers_){

		if (layer->SpeakerClickCheck(mouse_pos, correctionpos)) layer->ChengeSoundFlag();

	}

}