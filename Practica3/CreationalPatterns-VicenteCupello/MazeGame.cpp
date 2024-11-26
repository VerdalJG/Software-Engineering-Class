#include "MazeGame.h"
#include "Maze.h"
#include "Wall.h"
#include "Room.h"
#include "Door.h"
#include "IMazeFactory.h"
#include "IMazeBuilder.h"

MazeGame::~MazeGame()
{
	delete maze;
}

void MazeGame::GenerateMaze1()
{
	maze = new Maze(5, 3);
	Room* room0 = new Room(0);
	Room* room1 = new Room(1);
	Door* door = new Door(room0, room1);

	Maze::MazeGrid& grid = maze->GetGrid();

	// Create walls for the rooms' boundaries
	Wall* wallRoom0North = new Wall(); // North of room0
	Wall* wallRoom0West = new Wall(); // West of room0
	Wall* wallRoom0South = new Wall(); // South of room0

	// Set neighbors for room0
	room0->SetAdjacentNeighbor(wallRoom0North, EDirection::North);
	room0->SetAdjacentNeighbor(wallRoom0West, EDirection::West);
	room0->SetAdjacentNeighbor(wallRoom0South, EDirection::South);
	room0->SetAdjacentNeighbor(door, EDirection::East);

	Wall* wallRoom1North = new Wall(); // North of room1
	Wall* wallRoom1East = new Wall(); // East of room1
	Wall* wallRoom1South = new Wall(); // South of room1
	
	// Set neighbors for room1
	room1->SetAdjacentNeighbor(wallRoom1North, EDirection::North);
	room1->SetAdjacentNeighbor(wallRoom1East, EDirection::East);
	room1->SetAdjacentNeighbor(wallRoom1South, EDirection::South);
	room1->SetAdjacentNeighbor(door, EDirection::West);
	
	// Add to vector
	maze->AddRoom(room0);
	maze->AddRoom(room1);

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
				grid[i][j] = new Wall();
			}
		}
	}
}

void MazeGame::GenerateMaze2(IMazeFactory* factory)
{
	maze = factory->CreateMaze(5, 3);

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
}

void MazeGame::GenerateMaze3(IMazeBuilder* builder, IMazeFactory* factory)
{
	maze = builder->ConstructMaze(factory);
	PrintMaze();
	ResetMaze();
	printf("\n");
}

void MazeGame::PrintMaze()
{
	Maze::MazeGrid& grid = maze->GetGrid();
	for (int i = 0; i < maze->GetHeight(); i++)
	{
		for (int j = 0; j < maze->GetWidth(); j++)
		{
			grid[i][j]->Draw();
			if (j == maze->GetWidth() - 1)
			{
				printf("\n");
			}
		}
	}
}

void MazeGame::ResetMaze()
{
	delete maze;
	maze = nullptr;
}
