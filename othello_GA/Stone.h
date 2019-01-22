#pragma once
#include <iostream>
enum StoneStatus {
	EMPTY = 0,
	WHITE = 1,
	BLACK = 2,
};
class Stone
{
	StoneStatus stoneColor;
public:
	Stone();
	void setStoneColor(StoneStatus);
	void reverseStone();
	~Stone();
	StoneStatus getStoneColor();
};

