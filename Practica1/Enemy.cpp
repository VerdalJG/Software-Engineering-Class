#include "Enemy.h"
#include <windows.h>

Enemy::Enemy(Entity* playerPtr)
{
	_playerPtr = playerPtr;
}

void Enemy::Spawn()
{
	int spawnSide = rand() % 2;
	_xPos = spawnSide ? 120 : 0;
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

Entity* Enemy::CollisionCheck(Entity* enemies)
{
	if (_playerPtr->_xPos == _xPos) return;
	if (enemyXPos == bulletXPos)
	{
		enemyXPos = -1;
		bulletXPos = -1;
		break;
	}

	if (playerXPos == enemyXPos) return 0;
	if (enemyXPos == bulletXPos)
	{
		enemyXPos = -1;
		bulletXPos = -1;
		break;
	}

	return nullptr;
}

void Enemy::ResetEnemy()
{
	_xPos = -1;
}
