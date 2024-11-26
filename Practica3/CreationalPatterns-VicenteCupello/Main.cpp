#include <iostream>
#include "MazeGame.h"
#include "MazeBaseFactory.h"
#include "MazeBombFactory.h"
#include "MazeConcreteBuilderA.h"
#include "MazeConcreteBuilderB.h"

// Forward declare
void Task1();
void Task2();
void Task3();

int main()
{
	Task1();
    printf("============================================================\n");

	Task2();
	printf("============================================================\n");

	Task3();
}

void Task1()
{
	printf("Example 1 And 2\n");

	MazeGame* example1And2 = new MazeGame();
	example1And2->GenerateMaze1();
	example1And2->PrintMaze();
	printf("\n");
}

void Task2()
{
	printf("Example 3\n");
	printf("\n");
	printf("Base Maze: \n");
	MazeGame* example3 = new MazeGame();

	IMazeFactory* baseMazeFactory = new MazeBaseFactory();
	example3->GenerateMaze2(baseMazeFactory);
	example3->PrintMaze();
	example3->ResetMaze();
	delete baseMazeFactory;
	baseMazeFactory = nullptr;
	printf("\n");
	printf("Bomb Maze: \n");

	IMazeFactory* bombMazeFactory = new MazeBombFactory();
	example3->GenerateMaze2(bombMazeFactory);
	example3->PrintMaze();
	example3->ResetMaze();
	delete bombMazeFactory;
	baseMazeFactory = nullptr;
	printf("\n");
}

void Task3()
{
	printf("Example 4\n");
	MazeGame* example4 = new MazeGame();
	IMazeFactory* baseMazeFactory = new MazeBaseFactory();
	IMazeFactory* bombMazeFactory = new MazeBombFactory();
	IMazeBuilder* horizontalMazeBuilder = new MazeConcreteBuilderA();
	IMazeBuilder* verticalMazeBuilder = new MazeConcreteBuilderB();
	example4->GenerateMaze3(horizontalMazeBuilder, baseMazeFactory);
	example4->GenerateMaze3(horizontalMazeBuilder, bombMazeFactory);


	printf("Vertical Mazes:\n");
	printf("\n");

	example4->GenerateMaze3(verticalMazeBuilder, baseMazeFactory);
	example4->GenerateMaze3(verticalMazeBuilder, bombMazeFactory);

	delete baseMazeFactory;
	delete bombMazeFactory;
	delete horizontalMazeBuilder;
	delete verticalMazeBuilder;
}
