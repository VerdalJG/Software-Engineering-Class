#pragma once
#include "Entity.h"

class Enemy : public Entity
{
public: 
	Enemy(Entity* player);
	virtual void Spawn() override;
    virtual void Move() override;
	virtual bool CollisionCheck(Entity* bullets);
	virtual void Die();

private:
	Entity* _playerPtr;
};

