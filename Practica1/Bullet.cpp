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

bool Bullet::CollisionCheck(Entity* enemies)
{
	for (int i = 0; i < 5; i++)
	{
		if (_xPos == (enemies + i)->_xPos )
		{
			Die();
			(enemies + i)->Die();
			return true;
		}
	}
	if (_xPos > 120 || _xPos < 0) // Border Check
	{
		Die();
		return true;
	}
	return false;
}

void Bullet::Die() 
{
	_xPos = -1;
}

