#include "AbstructMiddleLeft.h"

class LayerManager;

class LayerML : public AbstructMiddleLeft{

public:

	LayerML(LayerManager* layermanager);

	~LayerML();

	virtual void Draw();

	virtual void ClickCheck(Vector2 mouse_pos);

private:

	virtual void MyClassDraw();

	LayerManager* layermanager_;

};