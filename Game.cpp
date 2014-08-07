#include "Game.h"
#include "Player.h"
#include "Enemy.h"

#include <iostream>

Game* Game::s_pInstance = 0;

bool Game::init(const char* title, int x, int y, int w, int h, int flags)
{
	if(SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		gWindow = SDL_CreateWindow(title, x, y, w, h, flags);

		if(gWindow != 0) {
			gRenderer = SDL_CreateRenderer(gWindow, -1, 0);

			if(gRenderer != 0) {
				SDL_SetRenderDrawColor(gRenderer, 0, 105, 132, 255);
			} else {
				return false;
			}
		} else {
			return false;
		}
	} else {
		return false;
	}

	TheTextureManager::Instance()->load("assets/PlayerDestroyed.png", "Player", gRenderer);
	//TheTextureManager::Instance()->load("assets/PShipFire.png", "Fire", gRenderer);
	gObjects.push_back(new Player(new LoaderParams(100, 100, 32, 30, "Player")));
	gObjects.push_back(new Enemy(new LoaderParams(300, 300, 32, 30, "Player")));
	gRun = true;

	return true;
}
void Game::render()
{
	SDL_RenderClear(gRenderer);
	for(std::vector<GameObject*>::size_type i = 0; i != gObjects.size(); i++)
		gObjects[i]->draw();
	SDL_RenderPresent(gRenderer);
}
void Game::hEvents()
{
	SDL_Event event;

	if(SDL_PollEvent(&event)) {
		switch(event.type) {
		case SDL_QUIT:
			gRun = false;
			break;
		case SDL_KEYDOWN:
			keys[event.key.keysym.sym] = true;
			break;
		case SDL_KEYUP:
			keys[event.key.keysym.sym] = false;
			break;
		default:
			break;
		}
	}
}
void Game::update()
{
	for(std::vector<GameObject*>::size_type i = 0; i != gObjects.size(); i++)
		gObjects[i]->update();
	if(isPressed(SDLK_w))
		player->update();

}
void Game::clean()
{
	SDL_DestroyWindow(gWindow);
	SDL_DestroyRenderer(gRenderer);
	SDL_Quit();	
}
