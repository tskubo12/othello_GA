#pragma once
#include "Header.h"
#include "Board.h"
#include "Player.h"
#include "AiPlayer.h"
#include "HumanPlayer.h"
#include "Point.h"
#include "Score.h"
class Game
{
	Board board_m;
	std::vector<std::shared_ptr<Player>> player;
	bool playerChoice(int &, Color);
public:
	Game();
	~Game();
	bool nextTurn(std::shared_ptr<Player> ,int &);
	bool start_game();
	void finish_game();
	
};

