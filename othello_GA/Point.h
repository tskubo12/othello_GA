#pragma once
#include "Header.h"
class Point
{
private:
	int x_m;
	int y_m;
	bool isOnBoard(int, int);

public:
	Point();
	Point(int,int);
	int getX () const;
	int getY () const;
	void printPoint();
	bool setPoint(int,int);
	bool setPoint(Point);
	bool incrementPoint(int, int);
	bool array_have_thisPoint(Point *,int const&);
	bool operator==(const Point&);
	void operator=(const Point&);
};

