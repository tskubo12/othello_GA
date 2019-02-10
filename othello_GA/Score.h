#pragma once
#include"Header.h"
#include "Stone.h"
#include "Board.h"
class Othello_Score
{
	int black_num;
	int white_num;
	int empty_num;
	void score_add(Color);
public:
	Othello_Score();
	void print_result();
	void compute_result(Board&);
};

