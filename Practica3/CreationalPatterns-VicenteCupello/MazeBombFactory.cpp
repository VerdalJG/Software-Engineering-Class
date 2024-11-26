#include "MazeBombFactory.h"
#include "DestructibleWall.h"
#include "Bomb.h"
#include "Door.h"
#include "Maze.h"

Maze* MazeBombFactory::CreateMaze(int width, int height)
{
    return new Maze(width, height);
}

IMapSite* MazeBombFactory::CreateRoom(int roomID)
{
    return new Bomb(roomID);
}

IMapSite* MazeBombFactory::CreateWall()
{
    return new DestructibleWall();
}

IMapSite* MazeBombFactory::CreateDoor(Room* room1, Room* room2)
{
    return new Door(room1, room2);
}
