#pragma once

class IMapSite;
class Room;
class Maze;

class IMazeFactory
{
public:
	virtual ~IMazeFactory() = default; 

	virtual Maze* CreateMaze(int width, int height) = 0;
	virtual IMapSite* CreateRoom(int roomID) = 0;
	virtual IMapSite* CreateWall() = 0;
	virtual IMapSite* CreateDoor(Room* room1, Room* room2) = 0;

};


