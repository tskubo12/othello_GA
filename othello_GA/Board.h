#pragma once
#include "Stone.h"
#include "Point.h"
#include "Score.h"
#include <iostream>
#include <stdlib.h>
#define BOARDSIZE 4

class Board
{
	Stone stoneOnBoard[BOARDSIZE][BOARDSIZE];
	void setVector(int& , int&);
	void setVector(Point&, Point&, int&, int&);
	void reversePointToPoint(Point, Point, Color, int const&, int const&);
	bool is_point_in_board(Point);
	bool point_have_enemyStone(Point,Color);
	bool isEmptyPoint(Point);
	bool canReversePointOnBoard(Point, Color);
	bool can_reach_myStonePoint(int const&, int const&, Color, Point &, Point &);
	Color getPointColor(Point);
	void reverceStoneOnBoard(int, int);
	

public:
	Board();
	~Board();
	void printBoard();
	void setStone(Point,Color);
	void reversePointOnBoard(Point ,Color);

	bool searchCanPutStone(Color, Point *, int &);
	void compute_result(Othello_Score&);
};

