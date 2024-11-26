#pragma once
#include "IMapSite.h"

class Room;

class Door : public IMapSite
{
public:
	Door(Room* room1, Room* room2);
	virtual void Enter() override;
	virtual void Draw() override { printf("D"); }

private:
	bool isOpen;
	Room* room1;
	Room* room2;

public:
	bool IsOpen() { return isOpen; }
	void SetIsOpen(bool isOpen) { this->isOpen = isOpen; }
};

