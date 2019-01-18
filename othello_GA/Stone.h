#pragma once
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
	~Stone();
	StoneStatus getStoneColor();
};

