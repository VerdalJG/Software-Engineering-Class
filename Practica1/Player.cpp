#include "Player.h"

/// <summary>
/// Initialize player
/// </summary>
/// <param name="speed"></param>
Player::Player(int speed)
{
	_xPos = -55;
	_speed = speed;
	_direction = Directions::Right;
}

void Player::Move(int direction)
{
	_xPos += direction * _speed;
	if (direction > 0) _direction = Directions::Right;
	if (direction < 0) _direction = Directions::Left;
}

void Player::OnCollide(Entity* other)
{
	return;
}