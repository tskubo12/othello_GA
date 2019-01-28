#pragma once
#include "Stone.h"
#include "Point.h"
#include <iostream>
#include<stdlib.h>
#define BOARDSIZE 4

class Board
{
	Stone stoneOnBoard[BOARDSIZE][BOARDSIZE];
	void setVector(int& , int&);
	void setVector(Point&, Point&, int&, int&);
	bool is_point_in_board(Point);
	bool point_have_enemyStone(Point,Color);
public:
	Board();
	~Board();
	void printBoard();
	void setStone(Point,Color);
	Color getPointColor(Point);
	Color getPointColor(int, int);
	void reverceStoneOnBoard(int, int);
	void reverceStoneOnBoard(Point);
	bool isEmptyPoint(Point);

	bool canReversePointOnBoard(Point, Color);
	void reversePointOnBoard(Point ,Color);
	void checkVector(Point, Point, int*, int*);
	void reversePointToPoint(Point, Point, Color, int const&,int const&);
	void reversePointToPoint(Point, Point, Color);
	bool can_reach_myStonePoint(int const&, int const&, Color,Point &,Point &);
	bool searchCanPutStone(Color, Point *, int &);
};

