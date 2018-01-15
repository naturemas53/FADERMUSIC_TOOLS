#pragma once

#include <vector>
#include "../GameScene.hpp"
#include "../../ESGLib.h"

class AbstructButton;
class PreviewSwitch;

class LayerManager;
class PlayAreaManager;

class AbstructMiddleRight;
class AbstructMiddleLeft;

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
	// �ϐ��錾
	std::vector<AbstructButton*> buttonlist_;
	PlayAreaManager* playareamanager_;
	LayerManager* layermanager_;
	PreviewSwitch* previewswitch_;
	AbstructMiddleRight* middleright_;
	AbstructMiddleLeft* middleleft_;
	JukeBox* jukebox_;

	// �֐��v���g�^�C�v

};