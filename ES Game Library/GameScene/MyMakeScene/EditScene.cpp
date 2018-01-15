#include "../../StdAfx.h"
#include "EditScene.hpp"
#include "../../MyMakeClasses/Button/FileButton.h"
#include "../../MyMakeClasses/Button/SongSelectButton.h"
#include "../../MyMakeClasses/PlayArea.h"
#include "../../MyMakeClasses/PreviewSwitch.h"
#include "../../MyMakeClasses/MiddleLeft/LayerML.h"
#include "../../MyMakeClasses/MiddleRight/SettingMR.h"
#include "../../MyMakeClasses/LayerManager.h"
#include "../../MyMakeClasses/PlayAreaManager.h"
#include "../../MyMakeClasses/InputSingleton.h"
#include "../../MyMakeClasses/JukeBox.h"

/// <summary>
/// Allows the game to perform any initialization it needs to before starting to run.
/// This is where it can query for any required services and load any non-graphic
/// related content.  Calling base.Initialize will enumerate through any components
/// and initialize them as well.
/// </summary>
bool EditScene::Initialize()
{
	// TODO: Add your initialization logic here

	StaticInput;//¶¬‚µ‚Äƒ}ƒEƒX‚Ì‰Šú‰»

	this->jukebox_ = new JukeBox();

	for (int i = 0; i < 5;i++){

		if (i != 1){
			this->buttonlist_.push_back(new FileButton(Vector3(i * 192.0f, 0.0f, 0.0f)));
		}
		else{
			this->buttonlist_.push_back(new SongSelectButton(Vector3(i * 192.0f, 0.0f, 0.0f),this->jukebox_));
		}
	}
	
	this->playareamanager_ = new PlayAreaManager();
	this->layermanager_ = new LayerManager();
	
	this->previewswitch_ = new PreviewSwitch(Vector3(1280.0f - 320.0f, 0.0f, 0.0f));
	this->middleright_ = new SettingMR();
	this->middleleft_ = new LayerML(this->layermanager_);

	return true;
}

/// <summary>
/// Finalize will be called once per game and is the place to release
/// all resource.
/// </summary>
void EditScene::Finalize()
{
	// TODO: Add your finalization logic here
	for (auto button : this->buttonlist_) delete button;
	delete this->playareamanager_;
	delete this->layermanager_;
	delete this->previewswitch_;
	delete this->middleleft_;
	delete this->middleright_;
	delete this->jukebox_;
}

/// <summary>
/// Allows the game to run logic such as updating the world,
/// checking for collisions, gathering input, and playing audio.
/// </summary>
/// <returns>
/// Scene continued value.
/// </returns>
int EditScene::Update()
{
    // TODO: Add your update logic here
	StaticInput.Update();

	this->jukebox_->Update();

	MouseState mouse_state = Mouse->GetState();

	POINT point = mouse_state.PointerPosition();
	Vector2 mouse_pos = Vector2_Zero;
	mouse_pos.x = point.x;
	mouse_pos.y = point.y;

	if (StaticInput.IsMouseButtonPressed(Mouse_Button1)){

		auto itr = this->buttonlist_.begin();
		auto end_itr = this->buttonlist_.end();

		for (; itr != end_itr;itr++){

			if ((*itr)->CollisionPointToMe(mouse_pos)){

				(*itr)->SetNowPush(true);
				break;

			}

		}

		if (previewswitch_->CollisionPointToMe(mouse_pos)){

			previewswitch_->SetNowPush(true);

		}

		this->middleright_->ClickCheck(mouse_pos);
		this->middleleft_->ClickCheck(mouse_pos);
		this->jukebox_->ClickCheck(mouse_pos);

	}

	if (StaticInput.IsMouseButtonReleased(Mouse_Button1)){

		for (int i = 0; i < 5;i++){

			if (i != 1){
			}
			else{
				if (this->buttonlist_[i]->IsPushed(mouse_pos)){

					SongSelectButton* button = (SongSelectButton*)this->buttonlist_[i];
					button->SongSelect();

				}


			}

			this->buttonlist_[i]->SetNowPush(false);

		}

		previewswitch_->SetNowPush(false);

		this->middleright_->ClickCheck(mouse_pos);
		this->jukebox_->ClickCheck(mouse_pos);

	}

	return 0;
}

/// <summary>
/// This is called when the game should draw itself.
/// </summary>
void EditScene::Draw()
{

	// TODO: Add your drawing code here
	GraphicsDevice.Clear(Color_CornflowerBlue);

	GraphicsDevice.BeginScene();

	GraphicsDevice.SetDefaultRenderTarget();

	SpriteBatch.Begin();

	for (auto button : this->buttonlist_) button->Draw();

	this->previewswitch_->Draw();

	SpriteBatch.End();
	
	this->jukebox_->Draw();

	this->playareamanager_->Draw();

	this->middleleft_->Draw();
	this->middleright_->Draw();
		
	GraphicsDevice.EndScene();
}
