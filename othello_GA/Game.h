#pragma once
#include "Header.h"
#include "Board.h"
#include "Player.h"
#include "Point.h"
#include "Score.h"
class Game
{
	Board board_m;
	Player player[2];
public:
	Game();
	~Game();
	bool nextTurn(Player & ,int &);
	bool start_game();
	void finish_game();
	
};

