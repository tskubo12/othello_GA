#pragma once
#include <iostream>
#include "Board.h"
#include "Player.h"
#include "Point.h"
#include "Score.h"
class Game
{
	Board board_m;
	Player player[2];
	Point canReverseStonePoint[20];
public:
	Game();
	~Game();
	bool nextTurn(Player & ,int &);
	bool start_game();
	bool finish_game();
	
};

