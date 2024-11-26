#pragma once
#include "IMazeBuilder.h"

class Maze;
class IMazeFactory;

class MazeConcreteBuilderB : public IMazeBuilder
{
public:
	virtual ~MazeConcreteBuilderB() = default;
	virtual Maze* ConstructMaze(IMazeFactory* factory) override;
};

