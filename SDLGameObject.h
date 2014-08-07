#ifndef __SDLGAMEOBJECT__
#define __SDLGAMEOBJECT__

#include "GameObject.h"
#include "Vector.h"

class SDLGameObject : public GameObject
{
public:
	SDLGameObject(const LoaderParams* pParams);

	virtual void draw();
	virtual void update();
	virtual void clean();

	Vector pos;
	Vector acc;
	Vector vel;

protected:
	int width;
	int height;

	int cRow;
	int cFrame;
	
	std::string textureID;
};
#endif