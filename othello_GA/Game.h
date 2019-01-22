#pragma once
#include <iostream>
#include "Board.h"
#include "Player.h"
#include "Point.h"
class Game
{
	Board board_m;
	Point canReverseStonePoint[20];
public:
	Game();
	~Game();
	bool nextTurn(Player *);
	Point *canReversePoint(Point);
	
};

