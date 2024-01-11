#pragma once
#include "Entity.h"
#include "Enemy.h"

class Bullet : public Entity
{
public:
	Bullet();
	virtual void Spawn(int xPos, Directions direction) override;
	virtual void Move() override;
	bool CollisionCheck(Entity* enemies);
	virtual void Die() override;


};

