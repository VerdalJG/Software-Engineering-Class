#pragma once
#include "Entity.h"

class Bullet : public Entity
{
public:
	Bullet();
	virtual void Spawn(int xPos, Directions direction) override;
	virtual void Move() override;
	virtual bool CollisionCheck(Entity* enemies) override;
	virtual void Die();


};

