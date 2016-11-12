#pragma once
#include"MC.h"
#include"SnakeInitgame.h"

class SnakeGameSystem{
public:
	void SetupSnake();
	void DrawSnake();
	void InputSnake();
	void LogicSnake(int val);
	void gameSnake(DWORD time, int val);
};



