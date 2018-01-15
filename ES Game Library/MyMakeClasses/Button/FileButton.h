#pragma once

#include "AbstructButton.h"

class FileButton : public AbstructButton {

public:

	FileButton(Vector3 pos):
		AbstructButton(pos, _T("FILE"), Vector2(192.0f,40.0f))
	{


	}

	virtual ~FileButton() = default;

private:


};