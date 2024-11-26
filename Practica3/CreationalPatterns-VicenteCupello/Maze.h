#pragma once
#include <vector>

class Room;
class IMapSite;

class Maze
{
public:
	using MazeGrid = std::vector<std::vector<IMapSite*>>;

	Maze(unsigned int width, unsigned int height);
	~Maze();
	void AddRoom(Room* room);
	Room* GetRoomByID(unsigned int roomID);

	// Assumes that all rows are of the same size
	void AddRow();

	// Assumes that all columns are of the same size
	void AddColumn();


protected:
	std::vector<Room*> rooms;
	MazeGrid grid;

public:
	std::vector<Room*> GetRooms() { return rooms; }
	MazeGrid& GetGrid() { return grid; }

	unsigned int GetWidth() { return grid.empty() ? 0 : grid[0].size(); }
	unsigned int GetHeight() { return grid.size(); }
};

