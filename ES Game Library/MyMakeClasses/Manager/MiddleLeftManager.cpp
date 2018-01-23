#include "MiddleLeftManager.h"
#include "../MiddleLeft/AbstructMiddleLeft.h"
#include "../MiddleLeft/LayerML.h"
#include "../MiddleLeft/SongSelectML.h"
#include "../MiddleLeft/BpmML.h"
#include "../InputSingleton.h"

MiddleLeftManager::MiddleLeftManager(std::shared_ptr<NoteManager> notemana_ptr, std::shared_ptr<JukeBox> jukebox_ptr){

	AbstructMiddleLeft::SetNoteManager(notemana_ptr);

	this->ml_map_["LAYER"] = new LayerML();
	this->ml_map_["SONGSELECT"] = new SongSelectML(jukebox_ptr);
	this->ml_map_["BPMSETTING"] = new BpmML();

	this->nowmiddleleft_ = this->ml_map_["LAYER"];

	this->buttons_.push_back(new TakeMLButton(Vector3(0.0f, 0.0f, 0.0f), _T("FILE(CAN'T USE)"), nullptr));
	this->buttons_.push_back(new TakeMLButton(Vector3(192.0f, 0.0f, 0.0f), _T("SONGSELECT"),this->ml_map_["SONGSELECT"]));
	this->buttons_.push_back(new TakeMLButton(Vector3(384.0f, 0.0f, 0.0f), _T("BPM SETTING"), this->ml_map_["BPMSETTING"]));
	this->buttons_.push_back(new TakeMLButton(Vector3(576.0f, 0.0f, 0.0f), _T("UNKNOWN"), nullptr));
	this->buttons_.push_back(new TakeMLButton(Vector3(768.0f, 0.0f, 0.0f), _T("UNKNOWN"), nullptr));


}

MiddleLeftManager::~MiddleLeftManager(){

	for(auto itr : this->ml_map_){

		delete itr.second;

	}

	for (auto button : this->buttons_) delete button;

}

void MiddleLeftManager::Draw(){

	//ボタンたちはどのスクリーンにもいないので、ここでB&E
	SpriteBatch.Begin();

	for (auto button : this->buttons_) button->Draw();

	SpriteBatch.End();

	this->nowmiddleleft_->Draw();

}

void MiddleLeftManager::ClickCheck(Vector2 mouse_pos){

	this->nowmiddleleft_->ClickCheck(mouse_pos);


		for (auto button : this->buttons_){

			if (button->CollisionPointToMe(mouse_pos)){

				button->SetNowPush(true);
				AbstructMiddleLeft* nextleft = button->GetMiddleLeft();

				if (nextleft == nullptr) {
					//何もしない
				}
				else if (nextleft == this->nowmiddleleft_){

					this->nowmiddleleft_ = this->ml_map_["LAYER"];

				}
				else{

					this->nowmiddleleft_ = nextleft;

				}

				break;
			}

		}

}