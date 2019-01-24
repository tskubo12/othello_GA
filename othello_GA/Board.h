#pragma once
#include "Stone.h"
#include "Point.h"
#include <iostream>
#include<stdlib.h>
#define BOARDSIZE 8

class Board
{
	Stone stoneOnBoard[BOARDSIZE][BOARDSIZE];
public:
	Board();
	~Board();
	void printBoard();
	void setStone(Point,StoneStatus);
	StoneStatus getPointColor(Point);
	StoneStatus getPointColor(int, int);
	void reverceStoneOnBoard(int, int);
	void reverceStoneOnBoard(Point);
	bool isEmptyPoint(Point);

	bool canReversePointOnBoard(Point, StoneStatus);
	bool reversePointOnBoard(Point ,StoneStatus);
	void checkVector(Point, Point, int*, int*);
	void reversePointToPoint(Point, Point, StoneStatus, int const*,int const*);
	bool searchPoint(int*, int*, StoneStatus,Point*,Point);
	bool searchCanPutStone(StoneStatus, Point *, int *);
};

