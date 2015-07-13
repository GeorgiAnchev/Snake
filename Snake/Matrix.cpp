#include "Coord.cpp"
#include <cstdio>
#include <cstdlib>


const int height = 20;
const int width = 30;
const char particle = (char)219;
const char foodParticle = 'O';

class Matrix
{
private:
	int matrix[height][width];
public:

	Matrix()
	{
		for (int i = 0; i < height; ++i)
		{
			for (int j = 0; j < width; ++j)this->matrix[i][j] = 0;
		}
	}

	void Update(Coord back, Coord front)
	{
		if (this->matrix[front.x][front.y] == -1) this->matrix[front.x][front.y] = 0; //Eating food
		this->matrix[front.x][front.y]++;
		this->matrix[back.x][back.y]--;
	}

	void Add(Coord A)
	{
		matrix[A.x][A.y]++;
	}

	void Print()
	{
		system("cls");
		for (int i = 0; i < height; ++i)
		{
			for (int j = 0; j < width; ++j)
			{
				//if( this->matrix[i][j] )printf("%c%c", particle, particle);
				if (this->matrix[i][j] > 0)printf("%c", particle);

				//else if( this->matrix[i][j] )printf("%c%c", particle, particle);
				else if (this->matrix[i][j] < 0)printf("%c", foodParticle);

				//else printf("  ");
				else printf(" ");
			}
			printf("|\n");
		}
		for (int j = 0; j < width; ++j)printf("-");//printf("-");
		printf("\n");
	}

	int IsTaken(Coord A)
	{
		if (this->matrix[A.x][A.y] > 0)return 1;     // there is snake
		if (this->matrix[A.x][A.y] < 0)return -1;    //there is food

	}

	void GenerateFood(int snakeLength)
	{
		int possiblePlaces = height*width - snakeLength;
		int randomValue = (rand() % possiblePlaces) + 1;

		for (int i = 0; i < height; ++i)
		{
			for (int j = 0; j < width; ++j)
			{
				if (this->matrix[i][j] <= 0)randomValue--; // if the place is empty
				if (randomValue < 1)
				{
					this->matrix[i][j] = -1;
					return;
				}
			}
		}
	}
};
