#pragma once
#include"Header.h"
#include "Stone.h"
#include "Point.h"
#include "Board.h"
class Player
{
	Color playerColor;
	Point nextPoint;
	bool playerStatus;
	vector<Point> canPutPointList;


public:
	Player();
	Player(Color);
	void printPlayerInfo();
	void printPointList();
	bool inputPoint(Point &);
	bool inputNextPoint();
	Color getPlayerColor();
	bool createCanPutPointList(Board&);
	bool list_have_thisPoint(Point);
};

