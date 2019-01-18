#include "stdafx.h"
#include "Stone.h"


Stone::Stone()
{
	stoneColor = EMPTY;
}

void Stone::setStoneColor(StoneStatus color) {
	stoneColor = color;
}

StoneStatus Stone::getStoneColor(){
	return stoneColor;
}

Stone::~Stone()
{
}
