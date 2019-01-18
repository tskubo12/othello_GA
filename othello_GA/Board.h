#pragma once
#include "Stone.h"
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
};

