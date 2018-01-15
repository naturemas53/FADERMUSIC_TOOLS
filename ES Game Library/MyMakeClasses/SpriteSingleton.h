#pragma once

#include "../ESGLib.h"

class SpriteSingleton{

public:

	static SpriteSingleton& GetInstance(){

		static SpriteSingleton instance;

		return instance;

	}

	SPRITE GetSprite(){ return sprites_; };

	~SpriteSingleton() = default;

private:

	SpriteSingleton(){

		sprites_ = GraphicsDevice.CreateSpriteFromFile(_T("button.png"));

	}

	SPRITE sprites_;


};

#define StaticSprite SpriteSingleton::GetInstance()