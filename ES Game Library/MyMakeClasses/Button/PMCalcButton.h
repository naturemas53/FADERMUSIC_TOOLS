#include "AbstructButton.h"

class PMCalcButton : public AbstructButton{

public:

	PMCalcButton(Vector3 pos, std::wstring name, Vector2 size, float addvalue) :
		AbstructButton(pos, name, size),
		ADDVALUE_(addvalue){};
	~PMCalcButton() = default;

template <typename T>
void CalcValue(T& value){

	value += (T)this->ADDVALUE_;

}

private:

	const float ADDVALUE_;

};