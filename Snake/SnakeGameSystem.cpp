#include "MC.h"
#include "SnakeGameSystem.h"
using namespace std;
bool gameOver;
const int _width = 20;
const int height = 20;
int x, y, fruitX, fruitY, score;
int tailX[100], tailY[100];
int nTail;
bool print;
enum eDirecton { STOP = 0, LEFT, RIGHT, UP, DOWN };
eDirecton dir;

void SnakeGameSystem::SetupSnake()
{
	gameOver = false;
	dir = STOP;
	nTail = 0;
	x = _width / 2;
	y = height / 2;
	fruitX = rand() % _width;
	fruitY = rand() % height;
	score = 0;
}

void SnakeGameSystem::DrawSnake()
{
	system("cls");
	for (int i = 0; i < _width + 2; i++)
		cout << "#";
	cout << endl;

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < _width; j++)
		{
			if (j == 0)
				cout << "#";
			if (i == y && j == x)
				cout << "O";
			else if (i == fruitY && j == fruitX)
				cout << "F";
			else
			{
				print = false;
				for (int k = 0; k < nTail; k++)
				{
					if (tailX[k] == j && tailY[k] == i)
					{
						cout << "o";
						print = true;
					}
				}
				if (!print)
					cout << ".";
			}


			if (j == _width - 1)
				cout << "#";
		}
		cout << endl;
	}

	for (int i = 0; i < _width + 2; i++)
		cout << "#";
	cout << endl;
	cout << "Score:" << score << endl;
}

void SnakeGameSystem::InputSnake()
{
	if (_kbhit())
	{
		switch (_getch())
		{
		case 'a':
			dir = LEFT;
			break;
		case 'd':
			dir = RIGHT;
			break;
		case 'w':
			dir = UP;
			break;
		case 's':
			dir = DOWN;
			break;
		case 'x':
			gameOver = true;
			break;
		}
	}
}

void SnakeGameSystem::LogicSnake(int val)
{
	int prevX = tailX[0];
	int prevY = tailY[0];
	int prev2X, prev2Y;
	tailX[0] = x;
	tailY[0] = y;
	for (int i = 1; i < nTail; i++)
	{
		prev2X = tailX[i];
		prev2Y = tailY[i];
		tailX[i] = prevX;
		tailY[i] = prevY;
		prevX = prev2X;
		prevY = prev2Y;
	}
	switch (dir)
	{
	case LEFT:
		x--;
		break;
	case RIGHT:
		x++;
		break;
	case UP:
		y--;
		break;
	case DOWN:
		y++;
		break;
	default:
		break;
	}
	//if (x > width || x < 0 || y > height || y < 0)
	//  gameOver = true;
	if (x >= _width) x = 0; else if (x < 0) x = _width - 1;
	if (y >= height) y = 0; else if (y < 0) y = height - 1;

	for (int i = 0; i < nTail; i++){
		if (tailX[i] == x && tailY[i] == y){
			gameOver = true;
			system("color c");
		}
	}

	if (x == fruitX && y == fruitY)
	{
		system("color a");
		score += 10 * val;
		fruitX = rand() % _width;
		fruitY = rand() % height;
		nTail++;
	}
}

void SnakeGameSystem::gameSnake(DWORD time, int val)
{
	system("cls");
	SetupSnake();
	while (!gameOver)
	{
		DrawSnake();
		InputSnake();
		LogicSnake(val);
		Sleep(time);
		system("color e");
	}
	system("color c");
	cout << endl << "Game Over!!" << endl;

}