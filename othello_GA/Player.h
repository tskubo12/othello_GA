#pragma once
#include "Stone.h"
#include "Point.h"
#include "Board.h"
#include <iostream>
class Player
{
	Color playerColor;
	Point *canReversePointBuf;
	Point nextPoint;
	bool playerStatus;
public:
	Player();
	Player(Color);
	~Player();
	void printPlayerInfo();
	bool canPutStone(Point);
	bool inputPoint(Point &);
	Color getPlayerColor();
	bool getCanPutPoint(Point, Point*);
};

