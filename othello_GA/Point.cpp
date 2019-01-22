#include "stdafx.h"
#include "Point.h"


Point::Point() {}

Point::Point(int x,int y)
{
	x_m = x;
	y_m = y;
}


Point::~Point()
{
}

int Point::getX() {
	return x_m;
}

int Point::getY() {
	return y_m;
}

void Point::printPoint()
{
	printf("(%d , %d)\n",x_m,y_m);
}

void Point::setPoint(int x, int y)
{
	x_m = x;
	y_m = y;
}

void Point::setPoint(Point point)
{
	setPoint(point.getX(), point.getY());
}

void Point::incrementPoint(int xPlus, int yPlus)//‚»‚ÌÀ•W‚É‰ÁZ‚µ‚½‚¢”’l‚ğˆø”‚Æ‚·‚é
{
	x_m += xPlus;
	y_m += yPlus;
}
