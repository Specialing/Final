#include "Game.h"

const int FRAMES = 60;
const int DELAY = 1000.0f / FRAMES;

int main(int argc, char* argv[])
{
	Uint32 start, time;

	if(TheGame::Instance()->init("Gremla", 100, 100, 640, 480, 0))
	{
		while(TheGame::Instance()->running())
		{
			start = SDL_GetTicks();

			TheGame::Instance()->hEvents();
			TheGame::Instance()->update();
			TheGame::Instance()->render();

			time = SDL_GetTicks() - start;

			if(time < DELAY)
				SDL_Delay((int)(DELAY - time));
		}
	} else {
		return -1;
	}
	TheGame::Instance()->clean();

	return 0;
}