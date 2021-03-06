#pragma once

#include <vector>
#include "../GameScene.hpp"
#include "../../ESGLib.h"
#include <memory>

class PlayAreaManager;
class NoteManager;
class MiddleRightManager;
class MiddleLeftManager;
class JukeBox;

class EditScene : public CGameScene {
public:
	EditScene()
	{
//		ContentRootDirectory(_T("Content"));
	}

	virtual ~EditScene()
	{
		Finalize();

#ifdef _INC_SQUIRREL
		Squirrel.ReleaseAllScripts();
#endif
#ifdef _INC_NUI
		NUI.ReleaseAllKinects();
#endif
#ifdef _INC_LIVE2D
		Live2D.ReleaseAllModels();
#endif
#ifdef _INC_EFFEKSEER
		Effekseer.ReleaseAllEffects();
#endif
#ifdef _INC_DIRECT2D
		Direct2D.ReleaseAllResources();
#endif
		MediaManager.ReleaseAllMedia();

		SoundDevice.ReleaseAllMusics();
		SoundDevice.ReleaseAllSounds();

		GraphicsDevice.ReleaseAllRenderTargets();
		GraphicsDevice.ReleaseAllStateBlocks();
		GraphicsDevice.ReleaseAllFonts();
		GraphicsDevice.ReleaseAllSprites();
		GraphicsDevice.ReleaseAllAnimationModels();
		GraphicsDevice.ReleaseAllModels();
		GraphicsDevice.ReleaseAllVertexBuffers();
		GraphicsDevice.ReleaseAllEffects();
	}

	virtual bool Initialize();

	virtual int  Update();
	virtual void Draw();

private:
	void Finalize();

private:
	// 変数宣言
	std::shared_ptr<PlayAreaManager> area_ptr_;
	MiddleRightManager* middlerightmanager_;
	MiddleLeftManager* middleleftmanager_;
	std::shared_ptr<NoteManager> notemana_ptr_;
	std::shared_ptr<JukeBox> jukebox_ptr_;

	//いつか使う
	//PreviewSwitch* previewswitch_;

	// 関数プロトタイプ

};
