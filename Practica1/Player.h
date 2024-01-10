#pragma once
#include "Entity.h"

class Player : public Entity
{
public:
	Player(int speed);
	void Move(int direction);
	void OnCollide(Entity* other);
	void Die();
	
};

