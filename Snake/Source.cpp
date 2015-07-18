#include <conio.h>
#include <iostream>
#include <deque>
#include <windows.h>
#include "Matrix.cpp"
using namespace std;

void GameRun()
{
	deque<Coord> snake;
	Matrix* matrix = new Matrix();
	Coord direction;
	direction.x = 0;
	direction.y = 1;
	char previous = 'd';

	for (int i = 0; i < 4; ++i) //initiate 3 unit long snake
	{
		Coord A;
		A.x = 3;
		A.y = i;
		matrix->Add(A);
		snake.push_front(A);
	}

	matrix->GenerateFood(snake.size());

	matrix->Print();

	bool running = true;
	while (running)
	{
		if (kbhit())
		{
			char key = getch();
			switch (key)
			{
			case 'a':{
				if (previous == 'd')break;
				direction.x = 0;
				direction.y = -1;
				previous = key;
				break;
			}
			case 'd':{
				if (previous == 'a')break;
				direction.x = 0;
				direction.y = 1;
				previous = key;
				break;
			}
			case 's':{
				if (previous == 'w')break;
				direction.x = 1;
				direction.y = 0;
				previous = key;
				break;
			}
			case 'w':{
				if (previous == 's')break;
				direction.x = -1;
				direction.y = 0;
				previous = key;
				break;
			}
			}

		}
		Coord next = snake.front();
		next.x += direction.x;
		next.y += direction.y;

		if (next.x < 0 || next.x >= height || next.y < 0 || next.y >= width){ return; } //hit a wall
		if (matrix->IsTaken(next) == 1) { return; }  // hit the snake
		if (matrix->IsTaken(next) == -1) //eat food
		{
			snake.push_back(snake.back());//extend snake
			matrix->Add(snake.back());//extend snake
			matrix->GenerateFood(snake.size());
		}

		matrix->Update(snake.back(), next);
		snake.pop_back();
		snake.push_front(next);
		//if( snake.size() = width*height )endGame;

		Sleep(50);
		matrix->Print();

		Sleep(50);

	}
}

int main()
{
	GameRun();
	return 0;
}

