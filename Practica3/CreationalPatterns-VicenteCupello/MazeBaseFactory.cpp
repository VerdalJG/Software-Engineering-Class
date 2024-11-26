#include "MazeBaseFactory.h"
#include "Room.h"
#include "Wall.h"
#include "Door.h"
#include "Maze.h"

Maze* MazeBaseFactory::CreateMaze(int width, int height)
{
    return new Maze(width, height);
}

IMapSite* MazeBaseFactory::CreateRoom(int roomID)
{
    return new Room(roomID);
}

IMapSite* MazeBaseFactory::CreateWall()
{
    return new Wall();
}

IMapSite* MazeBaseFactory::CreateDoor(Room* room1, Room* room2)
{
    return new Door(room1, room2);
}
