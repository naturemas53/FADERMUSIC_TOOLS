#include "AbstructMiddleRight.h"
#include "../Button/FreeButton.h"

class UniteSelectMR : public AbstructMiddleRight{

public:
	UniteSelectMR();
	~UniteSelectMR();

	virtual void ClickCheck(Vector2 mouse_pos);

private:

	virtual void MyClassDraw();

	FreeButton* doubleunitebutton_;
	FreeButton* heightbutton_;
	FreeButton* backbutton_;

};