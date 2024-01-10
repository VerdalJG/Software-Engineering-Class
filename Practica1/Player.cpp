#include "Player.h"

/// <summary>
/// Initialize player
/// </summary>
/// <param name="speed"></param>
Player::Player(int speed)
{
	_xPos = 55;
	_speed = speed;
	_direction = Directions::Right;
}

void Player::Move(int direction)
{
	_xPos += direction * _speed;
	if (direction > 0) _direction = Directions::Right;
	if (direction < 0) _direction = Directions::Left;
}

bool Player::CollisionCheck(Entity* enemies)
{
	for (int i = 0; i < 5; i++)
	{
		if (_xPos == (enemies + i)->_xPos)
		{
			Die();
			(enemies + i)->Die();
			break;
		}
	}
	return false;
}

void Player::Die()
{
	_alive = false;
}