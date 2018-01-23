#include "AbstructMiddleLeft.h"
#include "../Button/PMCalcButton.h"
#include "../Button/FreeButton.h"
#include <vector>

class BpmML : public AbstructMiddleLeft {

public:

	BpmML();
	~BpmML();

	virtual void ClickCheck(Vector2 mouse_pos);

private:

	virtual void MyClassDraw();

	std::vector<PMCalcButton*> bpmbuttons_;
	std::vector<PMCalcButton*> timingbuttons_;
	FreeButton* desidebutton_;

	int	bpm_;
	int timing_;

	Vector3 bpmpos_;
	Vector3 timingpos_;

};