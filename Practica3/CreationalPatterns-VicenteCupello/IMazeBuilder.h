#pragma once

class Maze;
class IMazeFactory;

class IMazeBuilder
{
public:
	virtual ~IMazeBuilder() = default;
	virtual Maze* ConstructMaze(IMazeFactory* mazeFactory) = 0;
};

