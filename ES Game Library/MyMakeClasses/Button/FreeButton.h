#include "AbstructButton.h"

class FreeButton : public AbstructButton{

public:
	FreeButton(Vector3 pos, std::wstring name) :
		AbstructButton(pos, name, this->IMAGESIZE_){};
	~FreeButton() = default;

private:

};