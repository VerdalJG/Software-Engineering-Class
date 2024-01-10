#include "Bullet.h"

Bullet::Bullet()
{
	_xPos = -1;
	_speed = 3;
	_direction = Directions::Left;
}

void Bullet::Spawn(int xPos, Directions direction)
{
	_direction = direction;
	_xPos = xPos + DirectionToInt();
}

void Bullet::Move()
{
	_xPos += DirectionToInt();
}

Entity* Bullet::CollisionCheck(Entity* enemies)
{
	for (int i = 0; i < 5; i++)
	{
		if ((enemies + i)->_xPos == _xPos)
		{
			ResetBullet();
			(enemies + i)->_xPos = -2;
			return;
		}
	}
	if (_xPos > 120 || _xPos < 0) // Border Check
	{
		ResetBullet();
		return;
	}
}

void Bullet::ResetBullet() 
{
	_xPos = -1;
}

