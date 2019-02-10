#pragma once
#include"Header.h"
#include "Stone.h"
#include "Point.h"
#include "Board.h"
class Player
{
	Color playerColor;
	Point nextPoint;
	vector<Point> canPutPointList;
	bool list_have_thisPoint(Point);

public:
	Player();
	Player(Color);
	void printPlayerInfo();
	void printPointList();
	//bool inputPoint(Point &);
	bool inputNextPoint();
	Color getPlayerColor();
	Point getNextPoint();
	bool createCanPutPointList(Board&);
};

