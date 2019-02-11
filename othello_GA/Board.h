#pragma once
#include"Header.h"
#include "Stone.h"
#include "Point.h"
#
#include <stdlib.h>

class Board
{
	Stone stoneOnBoard[BOARDSIZE][BOARDSIZE];
	void setVector(int& , int&);
	void setVector(Point&, Point&, int&, int&);
	void reversePointToPoint(Point, Point, Color, int const&, int const&);
	bool point_have_enemyStone(Point,Color);
	bool isEmptyPoint(Point);
	bool can_reach_myStonePoint(int const&, int const&, Color, Point &, Point &);
	void reverceStoneOnBoard(int, int);
	void reversePointOnBoard(Point, Color);

public:
	Board();
	~Board();
	Color getPointColor(Point);
	void printBoard();
	void setStone(Point,Color);
	bool canReversePointOnBoard(Point, Color);
};

