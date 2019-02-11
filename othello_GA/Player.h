#pragma once
#include"Header.h"
#include "Stone.h"
#include "Point.h"
#include "Board.h"
class Player
{
private:
	Color playerColor;

protected:
	Point nextPoint;
	PlayerType type;
	vector<Point> canPutPointList;
	bool list_have_thisPoint(Point);
	
public:
	Player();
	Player(Color);
	void printPlayerInfo();
	void printPointList();
	virtual bool inputNextPoint() = 0;
	Color getPlayerColor();
	Point getNextPoint();
	PlayerType getPlayerType();
	bool createCanPutPointList(Board&);
};

