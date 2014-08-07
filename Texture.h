#ifndef __TEXTUREMANAGER__
#define __TEXTUREMANAGER__

#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include <map>
#include <vector>

class TextureManager
{
public:
	TextureManager(){}
	~TextureManager(){}

	void load(std::string path, std::string id, SDL_Renderer* rRenderer);
	void draw(std::string id, int x, int y, int w, int h, SDL_Renderer* rRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);
	void drawFrame(std::string id, int x, int y, int w, int h, int row, int frame, SDL_Renderer* rRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);

	std::map<std::string, SDL_Texture*> tMap;

	static TextureManager* Instance() {
		if(s_pInstance == 0) {
			s_pInstance = new TextureManager();
			return s_pInstance;
		}
		return s_pInstance;
	}

private:
	static TextureManager* s_pInstance;
};
typedef TextureManager TheTextureManager;
#endif /* Defined (__TEXTUREMANAGER__) */