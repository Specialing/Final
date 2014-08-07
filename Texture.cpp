#include "Texture.h"

TextureManager* TextureManager::s_pInstance = 0;

void TextureManager::load(std::string path, std::string id, SDL_Renderer* rRenderer)
{
	SDL_Surface* gSurface = IMG_Load(path.c_str());

	SDL_Texture* gTexture = SDL_CreateTextureFromSurface(rRenderer, gSurface);
	SDL_FreeSurface(gSurface);

	tMap[id] = gTexture;
}
void TextureManager::draw(std::string id, int x, int y, int w, int h, SDL_Renderer* rRenderer, SDL_RendererFlip flip)
{
	SDL_Rect sRect;
	SDL_Rect dRect;

	sRect.x = 0;
	sRect.y = 0;
	sRect.w = dRect.w = w;
	sRect.h = dRect.h = h;

	dRect.x = x;
	dRect.y = y;

	SDL_RenderCopyEx(rRenderer, tMap[id], &sRect, &dRect, 0, 0, flip);
}
void TextureManager::drawFrame(std::string id, int x, int y, int w, int h, int row, int frame, SDL_Renderer* rRenderer, SDL_RendererFlip flip)
{
	SDL_Rect sRect;
	SDL_Rect dRect;

	sRect.x = w * frame;
	sRect.y = h * (row - 1);
	sRect.w = dRect.w = w;
	sRect.h = dRect.h = h;
	dRect.x = x;
	dRect.y = y;

	SDL_RenderCopyEx(rRenderer, tMap[id], &sRect, &dRect, 0, 0, flip);
}
