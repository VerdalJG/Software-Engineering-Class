#pragma once
#include "Room.h"

class Bomb : public Room
{
public:
	Bomb(unsigned int RoomID);
	virtual void Enter() override;
	virtual void Draw() override { printf("B"); }
};

