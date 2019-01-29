#pragma once
#include <iostream>
#include "Stone.h"
class Othello_Score
{
	int black_num;
	int white_num;
	int empty_num;
public:
	Othello_Score();
	~Othello_Score();
	void score_add(Color);
	void print_result();
};

