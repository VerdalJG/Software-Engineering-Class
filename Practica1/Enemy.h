#pragma once
#include "Entity.h"
#include "Bullet.h"

class Enemy : public Entity
{
public: 
	Enemy(Entity* player);
	bool CollisionCheck(Entity* bullets);
	virtual void Spawn() override;
    virtual void Move() override;
	virtual void Die();

private:
	Entity* _playerPtr;
};

