#include "stdafx.h"
#include "Point.h"


bool Point::isOnBoard(int x, int y)
{
	bool retval;
	if (x >= 0 && x < BOARDSIZE && y >= 0 && y < BOARDSIZE)
	{
		retval = true;
	}
	else {
		retval = false;
	}

	return retval;
}

Point::Point() {}

Point::Point(int x,int y)
{
	x_m = x;
	y_m = y;
}

int Point::getX() const{
	return x_m;
}

int Point::getY() const{
	return y_m;
}

void Point::printPoint()
{
	printf("(%d , %d)\n",x_m,y_m);
}

bool Point::setPoint(int x, int y)
{
	bool retval = false;
	if (isOnBoard(x, y)) {
		x_m = x;
		y_m = y;
		retval = true;
	}
	else {
		retval = false;
	}
	return retval;
}

bool Point::setPoint(Point point)
{
	int x = point.getX();
	int y = point.getY();

	return setPoint(x, y);
}
//その座標に加算したい数値を引数とするできなかった場合はfalseを返す
bool Point::incrementPoint(int xPlus, int yPlus)
{
	if(isOnBoard(x_m + xPlus,y_m + yPlus)){
		x_m += xPlus;
		y_m += yPlus;
		return true;
	}
	return false;
}

/*ポイント型のリスト内にこのオブジェクトの座標と一致するものがあるか*/
bool Point::array_have_thisPoint(Point *array,int const &length )
{
	for (int i = 0; i < length; i++,array++) {
		if (x_m == array->x_m && y_m == array->y_m)return true;
	}
	return false;
}

bool Point::operator==(const Point &point)
{
	if ((x_m == point.getX()) && (y_m == point.getY())) {
		return true;
	}
	else {
		return false;
	}
}

void Point::operator=(const Point &point)
{
	x_m = point.getX();
	y_m = point.getY();
}


