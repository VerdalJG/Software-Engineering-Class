#pragma once
#include "Entity.h"

class Enemy : public Entity
{
public: 
	Enemy(Entity* player);
	virtual void Spawn() override;
    virtual void Move() override;
	virtual Entity* CollisionCheck(Entity* enemies);
	void ResetEnemy();

private:
	Entity* _playerPtr;
};

