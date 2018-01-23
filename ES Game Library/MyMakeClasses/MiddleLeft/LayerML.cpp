#include "LayerML.h"
#include "../Layer.h"
#include "../Manager/LayerManager.h"

LayerML::LayerML(){

	this->layermanager_ = new LayerManager(this->notemana_ptr_);

}

LayerML::~LayerML(){

	delete this->layermanager_;

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