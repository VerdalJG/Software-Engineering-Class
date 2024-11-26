#include "Maze.h"
#include "Room.h"

Maze::Maze(unsigned int width, unsigned int height) :
	grid(MazeGrid(height, std::vector<IMapSite*>(width, nullptr)))
{
}

Maze::~Maze()
{	
	for (int i = 0; i < GetHeight(); i++)
	{
		for (int j = 0; j < GetWidth(); j++)
		{
			if (grid[i][j])
			{
				delete grid[i][j];
			}
		}
	}
	grid.clear();
}

void Maze::AddRoom(Room* room)
{
	rooms.push_back(room);
}

void Maze::AddRow()
{
	unsigned int width = GetWidth();
	std::vector<IMapSite*> newRow(width, nullptr); // New row with same width
	grid.push_back(newRow); // Adds the new row, increasing height
}

void Maze::AddColumn()
{
	for (std::vector<IMapSite*>& row : grid) 
	{
		row.push_back(nullptr); // Adds a new element to each row, increasing the amount of columns
	}
}


Room* Maze::GetRoomByID(unsigned int roomID)
{
	for (Room* room : rooms)
	{
		if (room->GetRoomID() == roomID)
		{
			return room;
		}
	}
}
