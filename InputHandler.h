#ifndef __INPUTS__
#define __INPUTS__

#include <SDL.h>

class InputHandler
{
public:
	static InputHandler* Instance()
	{
		if(s_pInstance == 0)
		{
			s_pInstance = new InputHandler();
		}
			return s_pInstance;
	}
	void update();
	void clean();

	bool isKeyDown();
	bool isKeyUp();

	const Uint8* keys;

private:
	InputHandler();
	~InputHandler() {}
	
	static InputHandler* s_pInstance;
};
typedef InputHandler TheInputHandler;
#endif