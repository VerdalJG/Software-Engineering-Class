#include "Entity.h"

Entity::Entity(int x, int speed)
{
	_xPos = x;
	_speed = speed;
	_direction = Directions::Right;
}

/// <summary>
/// Moves the entity
/// </summary>
/// <param name="direction">is -1 or 1. -1 is Left, 1 is right</param>
void Entity::Move(int direction)
{
	_xPos += direction * _speed;
	if (x > 0) _direction = Directions::Right;
	if (x < 0) _direction = Directions::Left;
}
