#pragma once

class Maze;
class IMazeFactory;
class IMazeBuilder;

class MazeGame
{
public:
	~MazeGame();
	
	void GenerateMaze1();
	void GenerateMaze2(IMazeFactory* factory);
	void GenerateMaze3(IMazeBuilder* builder, IMazeFactory* factory);
	void PrintMaze();
	void ResetMaze();

private:
	Maze* maze = nullptr;
};

