#pragma once
#include "IMazeFactory.h"

class Maze;

class MazeBaseFactory : public IMazeFactory
{
public:
	virtual Maze* CreateMaze(int width, int height);
	virtual IMapSite* CreateRoom(int roomID);
	virtual IMapSite* CreateWall();
	virtual IMapSite* CreateDoor(Room* room1, Room* room2);
};

