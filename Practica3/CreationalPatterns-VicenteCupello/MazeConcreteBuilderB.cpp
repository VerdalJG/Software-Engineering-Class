#include "MazeConcreteBuilderB.h"
#include "IMazeFactory.h"
#include "Maze.h"
#include "Room.h"
#include "Door.h"
#include "Wall.h"

Maze* MazeConcreteBuilderB::ConstructMaze(IMazeFactory* factory)
{
	Maze* maze = factory->CreateMaze(3, 5);

	IMapSite* room0 = factory->CreateRoom(0);
	IMapSite* room1 = factory->CreateRoom(1);

	Room* castedRoom0 = static_cast<Room*>(room0);
	Room* castedRoom1 = static_cast<Room*>(room1);

	IMapSite* door = factory->CreateDoor(castedRoom0, castedRoom1);

	Maze::MazeGrid& grid = maze->GetGrid();

	// Create walls for the rooms' boundaries
	IMapSite* wallRoom0North = factory->CreateWall(); // North of room0
	IMapSite* wallRoom0East = factory->CreateWall(); // East of room0
	IMapSite* wallRoom0West = factory->CreateWall(); // West of room0

	// Set neighbors for room0
	castedRoom0->SetAdjacentNeighbor(wallRoom0North, EDirection::North);
	castedRoom0->SetAdjacentNeighbor(wallRoom0East, EDirection::East);
	castedRoom0->SetAdjacentNeighbor(wallRoom0West, EDirection::West);
	castedRoom0->SetAdjacentNeighbor(door, EDirection::South);

	IMapSite* wallRoom1South = factory->CreateWall(); // South of room1
	IMapSite* wallRoom1East = factory->CreateWall(); // East of room1
	IMapSite* wallRoom1West = factory->CreateWall(); // West of room1

	// Set neighbors for room1
	castedRoom1->SetAdjacentNeighbor(wallRoom1South, EDirection::South);
	castedRoom1->SetAdjacentNeighbor(wallRoom1East, EDirection::East);
	castedRoom1->SetAdjacentNeighbor(wallRoom1West, EDirection::West);
	castedRoom1->SetAdjacentNeighbor(door, EDirection::North);

	maze->AddRoom(castedRoom0);
	maze->AddRoom(castedRoom1);

	// Place rooms and door
	grid[1][1] = room0;
	grid[2][1] = door;
	grid[3][1] = room1;

	// Place walls in the grid where appropriate
	grid[0][1] = wallRoom0North; // North of room0
	grid[1][0] = wallRoom0East; // East of room0
	grid[1][2] = wallRoom0West; // West of room0

	grid[4][1] = wallRoom1South; // South of room1
	grid[3][0] = wallRoom1East; // East of room1
	grid[3][2] = wallRoom1West; // West of room1

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
