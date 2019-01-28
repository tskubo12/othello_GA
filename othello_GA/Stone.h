#pragma once
#include <iostream>
enum Color {
	EMPTY = 0,
	WHITE = 1,
	BLACK = 2,
};
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

