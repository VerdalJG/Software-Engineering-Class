#include "Room.h"
#include "Wall.h"

Room::Room(unsigned int roomID)
{
    this->roomID = roomID;
    neighbors = std::vector<IMapSite*>(4, nullptr);
}

void Room::Enter()
{
}
