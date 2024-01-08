#pragma once
class Entity
{
	enum Directions
	{
		Left = -1,
		Right = 1
	};

public:
	Entity(int x, int speed);
	void Move(int x);


public:
	int _xPos;
	int _speed;
	Directions _direction;

};

