#include "Application.hpp"
#include "MazeSolver.hpp"
#include "Maze.hpp"
#include <iostream>
#include <time.h>

using namespace std;

int main(int argc, char* argv[]) {

	srand(time(0));

	Application::getInstance()->addWindow(new MazeSolver(new Maze(1)));
	//Application::getInstance()->addWindow(new MazeSolver(new Maze(2)));
	//Application::getInstance()->addWindow(new MazeSolver(new Maze(3)));
	Application::getInstance()->start();


	return 0;
}
