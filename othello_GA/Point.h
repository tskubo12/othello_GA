#pragma once
#include<iostream>
class Point
{
private:
	int x_m;
	int y_m;

public:
	Point();
	Point(int,int);
	~Point();
	int getX();
	int getY();
	void printPoint();
	void setPoint(int,int);
	void setPoint(Point);
	void incrementPoint(int, int);
	bool array_have_thisPoint(Point *,int const&);
};

