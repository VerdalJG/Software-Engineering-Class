#pragma once
#include "Entity.h"

class Player : public Entity
{
public:
	Player(int speed);
	void Move(int direction);
	bool CollisionCheck(Entity* other);
	void Die();
	
public:
	bool _alive = true;
};

