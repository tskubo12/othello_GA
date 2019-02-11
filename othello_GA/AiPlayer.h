#pragma once
#include "Player.h"
#include <random>
class AiPlayer :
	public Player
{
public:
	AiPlayer(Color);
	~AiPlayer();
	virtual bool inputNextPoint();
};

