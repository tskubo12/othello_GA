#pragma once
#include "Stone.h"
#include "Point.h"
#include "Board.h"
#include <iostream>>
class Player
{
	StoneStatus playerColor;
	Point *canReversePointBuf;
	Point nextPoint;
public:
	Player(StoneStatus);
	~Player();
	void printPlayerInfo();
	bool canPutStone(Point);
	Point inputPoint();
	StoneStatus getPlayerColor();
};

