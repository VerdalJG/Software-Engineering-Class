#include "Door.h"
#include "Room.h"

Door::Door(Room* room1, Room* room2)
{
	this->room1 = room1;
	this->room2 = room2;
}

void Door::Enter()
{
}
