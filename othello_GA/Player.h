#pragma once
#include "Stone.h"
#include <iostream>>
class Player
{
	StoneStatus playerColor;
public:
	Player(StoneStatus);
	~Player();
	void printPlayerInfo();
	
};

