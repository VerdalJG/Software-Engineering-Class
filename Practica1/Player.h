#pragma once
#include "Entity.h"
#include "Enemy.h"

class Player : public Entity
{
public:
	Player(int speed);
	bool CollisionCheck(Entity* other);
	virtual void Move(int direction);
    
	virtual void Die() override;
	
public:
	bool _alive = true;
};

