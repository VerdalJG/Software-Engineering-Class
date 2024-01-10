#include "Entity.h"

void Entity::SetDirection(int direction)
{
	_direction = direction < 0 ? Directions::Left : Directions::Right;
}

int Entity::DirectionToInt()
{
	if (_direction == Directions::Left) return -1;
	else return 1;
}






