#include "AbstructMiddleRight.h"
#include <vector>

class PMCalcButton;
class NoteMakeButton;
class FreeButton;

class SettingMR : public AbstructMiddleRight{

public:

	SettingMR(bool uniteflag,std::vector<AbstructNote*>& selectnote);
	~SettingMR();

	virtual void ClickCheck(Vector2 mouse_pos);
	//void SetNoteP();

private:
	

	virtual void MyClassDraw();

	void PressCheck(Vector2 mouse_pos);
	void ReleaseRun(Vector2 mouse_pos);
	
	std::list<PMCalcButton*> heightbuttons_;
	std::list<PMCalcButton*> timingbuttons_;

	std::vector<AbstructNote*> notes_;

	FreeButton* desidebutton_;

	float height_;
	int timing_;
	bool uniteflag_;

};