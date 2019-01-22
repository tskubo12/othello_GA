#include "stdafx.h"
#include "Stone.h"


Stone::Stone()
{
	stoneColor = EMPTY;
}

void Stone::setStoneColor(StoneStatus color) {
	stoneColor = color;
}

void Stone::reverseStone()
{
	if (stoneColor == WHITE) stoneColor = BLACK;
	else if (stoneColor == BLACK) stoneColor = WHITE;
	else std::cout << "there are not Stone \n";
}

StoneStatus Stone::getStoneColor(){
	return stoneColor;
}

Stone::~Stone()
{
}
