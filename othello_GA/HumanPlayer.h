#pragma once
#include "Player.h"
class HumanPlayer:
	public Player
{
public:
	HumanPlayer(Color);
	~HumanPlayer();
	virtual bool inputNextPoint();
};

