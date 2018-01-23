#include "AbstructMiddleLeft.h"
#include <memory>

class FreeButton;

class SongSelectML : public AbstructMiddleLeft{

public:

	SongSelectML(std::shared_ptr<JukeBox> jukebox_ptr);
	~SongSelectML();

	virtual void ClickCheck(Vector2 mouse_pos);

private:

	virtual void MyClassDraw();

	FreeButton* button_;
	std::shared_ptr<JukeBox> jukebox_ptr_;

};