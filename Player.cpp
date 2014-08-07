#include "Player.h"

Player::Player(const LoaderParams* pParams) : SDLGameObject(pParams)
{

}
void Player::draw()
{
	SDLGameObject::draw();
}
void Player::update()
{
	events();
	cFrame = int(((SDL_GetTicks() / 100) % 6));
	SDLGameObject::update();
}
void Player::events()
{
	vel.setX(1);
}
void Player::clean()
{
}