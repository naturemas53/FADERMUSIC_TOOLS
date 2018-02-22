#include "../../StdAfx.h"
#include "EditScene.hpp"
#include "../../MyMakeClasses/Manager/PlayAreaManager.h"
#include "../../MyMakeClasses/Manager/NoteManager.h"
#include "../../MyMakeClasses/InputSingleton.h"
#include "../../MyMakeClasses/JukeBox.h"
#include "../../MyMakeClasses/Manager/MiddleRightManager.h"
#include "../../MyMakeClasses/Manager/MiddleLeftManager.h"
#include "../../MyMakeClasses/Note/AbstructNote.h"

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

	AbstructNote::SetClapSound();

	this->jukebox_ptr_ = std::shared_ptr<JukeBox>(new JukeBox());

	this->notemana_ptr_ = std::shared_ptr<NoteManager>(new NoteManager(this->jukebox_ptr_));

	this->area_ptr_ = std::shared_ptr<PlayAreaManager>(new PlayAreaManager(this->notemana_ptr_));
	
	this->middlerightmanager_ = new MiddleRightManager(this->notemana_ptr_,this->area_ptr_);
	this->middleleftmanager_ = new MiddleLeftManager(this->notemana_ptr_,this->jukebox_ptr_);

	return true;
}

/// <summary>
/// Finalize will be called once per game and is the place to release
/// all resource.
/// </summary>
void EditScene::Finalize()
{
	// TODO: Add your finalization logic here

	delete this->middleleftmanager_;
	delete this->middlerightmanager_;

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

	this->jukebox_ptr_->Update();
	this->notemana_ptr_->Update();

	MouseState mouse_state = Mouse->GetState();

	POINT point = mouse_state.PointerPosition();
	Vector2 mouse_pos = Vector2_Zero;
	mouse_pos.x = (float)point.x;
	mouse_pos.y = (float)point.y;


	if (StaticInput.IsMouseLeftButtonPush()){
		this->middlerightmanager_->ClickCheck(mouse_pos);
		this->middleleftmanager_->ClickCheck(mouse_pos);
	}

	this->jukebox_ptr_->ClickCheck(mouse_pos);


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
	
	this->jukebox_ptr_->Draw();

	this->area_ptr_->Draw();

	this->middleleftmanager_->Draw();
	this->middlerightmanager_->Draw();
		
	GraphicsDevice.EndScene();
}