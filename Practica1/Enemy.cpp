#include "Enemy.h"
#include <windows.h>

Enemy::Enemy(Entity* playerPtr)
{
	_playerPtr = playerPtr;
	_xPos = -5;
}

void Enemy::Spawn()
{
	int spawnSide = rand() % 2;
	_xPos = spawnSide ? 120 : 0;
	_direction = spawnSide ? Directions::Left : Directions::Right;
}

void Enemy::Move()
{
	if (_xPos > _playerPtr->_xPos)
	{
		_xPos += -1;	
	}
	else if (_xPos < _playerPtr->_xPos)
	{	
		_xPos += 1;
	}
}

bool Enemy::CollisionCheck(Entity* bullets)
{
	if (_playerPtr->_xPos == _xPos)
	{
		Die();
		_playerPtr->Die();
		return true;
	}

	for (int i = 0; i < 5; i++)
	{
		if (_xPos == (bullets + i)->_xPos)
		{
			Die();
			(bullets + i)->Die();
			return true;
		}
	}
	return false;
}

void Enemy::Die()
{
	_xPos = -5;
}
