#include "Enemy.h"

Enemy::Enemy(const LoaderParams* pParams) : SDLGameObject(pParams)
{
}

void Enemy::draw()
{
	SDLGameObject::draw();
}
void Enemy::update()
{
	pos.setX(pos.getX()+1);
	pos.setY(pos.getY()-1);

	cFrame = int(((SDL_GetTicks() / 100) % 6));
}
void Enemy::clean()
{
}