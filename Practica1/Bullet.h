#pragma once
#include "Entity.h"

class Bullet : public Entity
{
public:
	Bullet();
	virtual void Spawn(int xPos, Directions direction) override;
	virtual void Move();
	virtual Entity* CollisionCheck(Entity* enemies);
	void ResetBullet();


};

