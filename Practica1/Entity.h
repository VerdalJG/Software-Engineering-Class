#pragma once
class Entity
{
protected:
	enum class Directions
	{
		Left,
		Right
	};

public:
	void SetDirection(int direction);
	virtual void Move();
	virtual Entity* CollisionCheck(Entity* coll);
	int DirectionToInt();
	virtual void Spawn(int xPos, Directions direction) {};
	virtual void Spawn() {};
	virtual void Die();

public:
	int _xPos = -1;
	Directions _direction = Directions::Left;
	int _speed = 1;
	void (*DeathFunction)();
	
};

