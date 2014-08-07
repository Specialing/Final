#include "SDLGameObject.h"
#include "Game.h"

SDLGameObject::SDLGameObject(const LoaderParams* pParams) : GameObject(pParams), pos(pParams->getX(), pParams->getY()), vel(0,0)
{
	width = pParams->getW();
	height = pParams->getH();
	textureID = pParams->getID();

	cRow = 1;
	cFrame = 1;
}
void SDLGameObject::draw()
{
	TheTextureManager::Instance()->drawFrame(textureID, (int)pos.getX(), (int)pos.getY(), width, height, cRow, cFrame, TheGame::Instance()->getRenderer());
}
void SDLGameObject::update()
{
}
void SDLGameObject::clean()
{
}