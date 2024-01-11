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
	int DirectionToInt();
	virtual void Move() {};
	virtual void Spawn(int xPos, Directions direction) {};
	virtual void Spawn() {};
	virtual void Die() {};

public:
	int _xPos = -1;
	int _speed = 1;
	Directions _direction = Directions::Left;
	
};

