#include "LayerML.h"
#include "../Layer.h"
#include "../LayerManager.h"

LayerML::LayerML(LayerManager* layermanager){

	this->layermanager_ = layermanager;

}

LayerML::~LayerML(){

}

void LayerML::Draw(){

	this->layermanager_->NoteDraw();

	this->AbstructMiddleLeft::Draw();

}

void LayerML::MyClassDraw(){

	this->layermanager_->Draw();

}

void LayerML::ClickCheck(Vector2 mouse_pos){

	this->layermanager_->ClickCheck(mouse_pos,this->POS_);

}