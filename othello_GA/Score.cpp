#include "stdafx.h"
#include "Score.h"


Othello_Score::Othello_Score()
{
	black_num = 0;
	white_num = 0;
	empty_num = 0;
}


Othello_Score::~Othello_Score()
{
}

void Othello_Score::score_add(Color color)
{
	switch (color)
	{
	case EMPTY:
		empty_num++;
		break;
	case WHITE:
		white_num++;
		break;
	case BLACK:
		black_num++;
		break;
	default:
		break;
	}
}

void Othello_Score::print_result()
{
	printf("BLACK : %d\n", black_num);
	printf("WHITE : %d\n", white_num);
	printf("EMPTY : %d\n", empty_num);

	if (black_num > white_num) std::cout << "WINNER : BLACK \n";
	else if (white_num > black_num) std::cout << "WINNER : WHITE \n";
}
