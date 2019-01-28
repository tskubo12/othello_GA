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

void Point::incrementPoint(int xPlus, int yPlus)//���̍��W�ɉ��Z���������l�������Ƃ���
{
	x_m += xPlus;
	y_m += yPlus;
}

/*�|�C���g�^�̃��X�g���ɂ��̃I�u�W�F�N�g�̍��W�ƈ�v������̂����邩*/
bool Point::array_have_thisPoint(Point *array,int const &length )
{
	for (int i = 0; i < length; i++,array++) {
		if (x_m == array->x_m && y_m == array->y_m)return true;
	}
	return false;
}
