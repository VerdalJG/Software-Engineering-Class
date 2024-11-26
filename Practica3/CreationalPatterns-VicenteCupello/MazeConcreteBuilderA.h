#pragma once
#include "IMazeBuilder.h"

class Maze;
class IMazeFactory;


class MazeConcreteBuilderA : public IMazeBuilder
{
public:
	virtual ~MazeConcreteBuilderA() = default;
	virtual Maze* ConstructMaze(IMazeFactory* factory) override;
};

