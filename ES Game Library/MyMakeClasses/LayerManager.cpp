#include "LayerManager.h"
#include "Layer.h"

LayerManager::LayerManager(){

	for (int i = 0; i < 8; i++){

		this->layers_.push_back(new Layer(Vector3( (i / 4)* 480.0f,(i % 4) * 70.0f,0.0f),i));

	}

}

LayerManager::~LayerManager(){

	for (auto layer : this->layers_) delete layer;

}

void LayerManager::Draw(){

	for (auto layer : this->layers_) layer->ScreenDraw();

}

void LayerManager::NoteDraw(){

	for (auto layer : this->layers_){

		layer->NoteDrawBegin();
		layer->NoteDrawEnd();

	}

}

void LayerManager::ClickCheck(Vector2 mouse_pos, Vector3 correctionpos){

	for (auto layer : this->layers_){

		if (layer->SpeakerClickCheck(mouse_pos, correctionpos)) layer->ChengeSoundFlag();

	}

}