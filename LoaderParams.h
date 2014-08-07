#ifndef __LOADERPARAMS__
#define __LOADERPARAMS__

#include "Texture.h"

class LoaderParams
{
public:
	LoaderParams(int x, int y, int w, int h, std::string ID) : m_x(x), m_y(y), width(w), height(h), textureID(ID){}
	~LoaderParams(){}

	int getX() const { return m_x; }
	int getY() const { return m_y; }

	int getW() const { return width; }
	int getH() const { return height; }

	std::string getID() const { return textureID; }

private:
	int m_x;
	int m_y;

	int width;
	int height;

	std::string textureID;
};
#endif