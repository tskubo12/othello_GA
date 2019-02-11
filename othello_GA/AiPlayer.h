#pragma once
#include "Player.h"
class AiPlayer :
	public Player
{
public:
	AiPlayer(Color);
	~AiPlayer();
	virtual bool inputNextPoint();
};

