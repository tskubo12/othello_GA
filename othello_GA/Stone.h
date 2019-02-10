#pragma once
#include "Header.h"
class Stone
{
	Color stoneColor;
public:
	Stone();
	void setStoneColor(Color);
	void reverseStone();
	~Stone();
	Color getStoneColor();
	Color getEnemyColor(Color);
};

