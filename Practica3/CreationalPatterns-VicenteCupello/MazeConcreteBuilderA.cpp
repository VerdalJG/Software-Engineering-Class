#include "MazeConcreteBuilderA.h"
#include "IMazeFactory.h"
#include "Maze.h"
#include "Room.h"
#include "Door.h"
#include "Wall.h"

Maze* MazeConcreteBuilderA::ConstructMaze(IMazeFactory* factory)
{
	Maze* maze = factory->CreateMaze(5, 3);

	IMapSite* room0 = factory->CreateRoom(0);
	IMapSite* room1 = factory->CreateRoom(1);

	Room* castedRoom0 = static_cast<Room*>(room0);
	Room* castedRoom1 = static_cast<Room*>(room1);

	IMapSite* door = factory->CreateDoor(castedRoom0, castedRoom1);

	Maze::MazeGrid& grid = maze->GetGrid();

	// Create walls for the rooms' boundaries
	IMapSite* wallRoom0North = factory->CreateWall(); // North of room0
	IMapSite* wallRoom0West = factory->CreateWall(); // West of room0
	IMapSite* wallRoom0South = factory->CreateWall(); // South of room0

	// Set neighbors for room0
	castedRoom0->SetAdjacentNeighbor(wallRoom0North, EDirection::North);
	castedRoom0->SetAdjacentNeighbor(wallRoom0West, EDirection::West);
	castedRoom0->SetAdjacentNeighbor(wallRoom0South, EDirection::South);
	castedRoom0->SetAdjacentNeighbor(door, EDirection::East);

	IMapSite* wallRoom1North = factory->CreateWall(); // North of room1
	IMapSite* wallRoom1East = factory->CreateWall(); // East of room1
	IMapSite* wallRoom1South = factory->CreateWall(); // South of room1

	// Set neighbors for room1
	castedRoom1->SetAdjacentNeighbor(wallRoom1North, EDirection::North);
	castedRoom1->SetAdjacentNeighbor(wallRoom1East, EDirection::East);
	castedRoom1->SetAdjacentNeighbor(wallRoom1South, EDirection::South);
	castedRoom1->SetAdjacentNeighbor(door, EDirection::West);

	maze->AddRoom(castedRoom0);
	maze->AddRoom(castedRoom1);

	// Place rooms and door
	grid[1][1] = room0;
	grid[1][2] = door;
	grid[1][3] = room1;

	// Place walls in the grid where appropriate
	grid[0][1] = wallRoom0North; // North of room0
	grid[1][0] = wallRoom0West; // West of room0
	grid[2][1] = wallRoom0South; // South of room0

	grid[0][3] = wallRoom1North; // North of room1
	grid[1][4] = wallRoom1East; // East of room1
	grid[2][3] = wallRoom1South; // South of room1

	for (int i = 0; i < maze->GetHeight(); i++)
	{
		for (int j = 0; j < maze->GetWidth(); j++)
		{
			if (!grid[i][j])
			{
				grid[i][j] = factory->CreateWall();
			}
		}
	}
	return maze;
}
