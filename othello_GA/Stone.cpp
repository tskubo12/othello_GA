#include "stdafx.h"
#include "Stone.h"


Stone::Stone()
{
	stoneColor = EMPTY;
}

void Stone::setStoneColor(Color color) {
	stoneColor = color;
}

void Stone::reverseStone()
{
	if (stoneColor == WHITE) stoneColor = BLACK;
	else if (stoneColor == BLACK) stoneColor = WHITE;
	else std::cout << "there are not Stone \n";
}

Color Stone::getStoneColor(){
	return stoneColor;
}

Color Stone::getEnemyColor(Color myColor)
{
	if (myColor == BLACK) return WHITE;
	else if(myColor == WHITE) return BLACK;
	else std::cout << "this Point dont have Stone";
}

Stone::~Stone()
{
}
