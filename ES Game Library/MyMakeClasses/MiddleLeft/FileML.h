#include "AbstructMiddleLeft.h"
#include "../Button/FreeButton.h"

class FileML : public AbstructMiddleLeft{

public:

	FileML();
	~FileML();

	virtual void ClickCheck(Vector2 mouse_pos);
private:

	virtual void MyClassDraw();

	FreeButton* openbutton_;
	FreeButton* savebutton_;

};