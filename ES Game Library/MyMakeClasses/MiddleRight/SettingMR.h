#include "AbstructMiddleRight.h"
#include <list>

class PMCalcButton;
class NoteMakeButton;

class SettingMR : public AbstructMiddleRight{

public:

	SettingMR();
	~SettingMR();

	virtual void ClickCheck(Vector2 mouse_pos);
	//void SetNoteP();

private:

	virtual void MyClassDraw();

	void PressCheck(Vector2 mouse_pos);
	void ReleaseRun(Vector2 mouse_pos);
	
	std::list<PMCalcButton*> layerbuttons_;
	std::list<PMCalcButton*> areabuttons_;
	std::list<PMCalcButton*> heightbuttons_;
	std::list<PMCalcButton*> timingbuttons_;
	NoteMakeButton* notemakebutton_;

	int layer_;
	int area_;
	float height_;
	int timing_;

};