#include "stdafx.h"
#include "Board.h"


Board::Board()//�Q�[���J�n���̃{�[�h�̏�
{
	stoneOnBoard[BOARDSIZE / 2 - 1][BOARDSIZE / 2 - 1].setStoneColor(WHITE);
	stoneOnBoard[BOARDSIZE / 2][BOARDSIZE / 2].setStoneColor(WHITE);
	stoneOnBoard[BOARDSIZE / 2][BOARDSIZE / 2 - 1].setStoneColor(BLACK);
	stoneOnBoard[BOARDSIZE / 2 - 1][BOARDSIZE / 2].setStoneColor(BLACK);
}


Board::~Board()
{
}

void Board::printBoard() {
	int a;
	std::cout << "�@";
	for (int i = 0; i < BOARDSIZE; i++) {
		std::cout << i << " " ;
	}
	std::cout << "\n";
	for (int rowNumber = 0; rowNumber < BOARDSIZE; rowNumber++) {
		std::cout << rowNumber << " ";
		for(int columnNumber = 0 ; columnNumber < BOARDSIZE; columnNumber++){
			switch (stoneOnBoard[rowNumber][columnNumber].getStoneColor())
			{
			case EMPTY:
				std::cout << "��";
				break;
			case BLACK:
				std::cout << "��";
				break;
			case WHITE:
				std::cout << "��";
				break;
			default:
				std::cout << "E";
				break;
			}
		}
		std::cout << "\n";
	}
		
}

void Board::setStone(Point point,StoneStatus playerColor)
{
	stoneOnBoard[point.getY()][point.getX()].setStoneColor(playerColor);
}

StoneStatus Board::getPointColor(Point point)
{
	return stoneOnBoard[point.getY()][point.getX()].getStoneColor();
}

StoneStatus Board::getPointColor(int x, int y)
{

	return stoneOnBoard[y][x].getStoneColor();
}

void Board::reverceStoneOnBoard(int x, int y)
{
	stoneOnBoard[y][x].reverseStone();
}

void Board::reverceStoneOnBoard(Point point)
{
	reverceStoneOnBoard(point.getX(), point.getY());
}

bool Board::isEmptyPoint(Point point)//�w�肵�����W�ɂ܂��΂��u����ĂȂ���
{
	if (getPointColor(point) == EMPTY) {
		return true;
	}
	else {
//		std::cout << "cannot put ";
//		point.printPoint();
//		std::cout << "\n";
		return false;
	}
}

bool Board::canReversePointOnBoard(Point putPoint,StoneStatus playerColor)//putPoint�ɒu�����Ƃ��\�ł��邩
{
	//putPoint���W�̎���̌������s��
	int flagCount = 0;
	int const x = putPoint.getX();
	int const y = putPoint.getY();
	Point sarchResult,toPoint;
	for(int searchPointY =y - 1;searchPointY <= y + 1;searchPointY++){
		for (int searchPointX = x - 1; searchPointX <= x + 1; searchPointX++) {
			int vectorX, vectorY;
			if (searchPointX < 0 || searchPointX > 7 || searchPointY < 0 || searchPointY > 7) continue;
			if (getPointColor(searchPointX, searchPointY) != playerColor && getPointColor(searchPointX,searchPointY) != EMPTY) {
				sarchResult = Point(searchPointX,searchPointY);
				checkVector(sarchResult, putPoint, &vectorX, &vectorY);//����������������߂�
				if (searchPoint(&vectorX, &vectorY, playerColor, &toPoint, putPoint)) {
//					reversePointToPoint(toPoint, putPoint, playerColor, &vectorX, &vectorY);
					return true;
				}
			}
		}
	}
	return false;
}
bool Board::reversePointOnBoard(Point putPoint, StoneStatus playerColor)//�����̍��W�ɐ΂��\�Ȑ΂͂Ђ�����Ԃ�
{
	int flagCount = 0;
	//putPoint���W�̎���̌������s��
	int const x = putPoint.getX();
	int const y = putPoint.getY();
	Point sarchResult, toPoint;
	for (int searchPointY = y - 1; searchPointY <= y + 1; searchPointY++) {
		for (int searchPointX = x - 1; searchPointX <= x + 1; searchPointX++) {
			int vectorX, vectorY;
			if (searchPointX < 0 || searchPointX > 7 || searchPointY < 0 || searchPointY > 7) continue;
			if (getPointColor(searchPointX, searchPointY) != playerColor && getPointColor(searchPointX, searchPointY) != EMPTY) {
				sarchResult = Point(searchPointX, searchPointY);
				checkVector(sarchResult, putPoint, &vectorX, &vectorY);//����������������߂�
				if (searchPoint(&vectorX, &vectorY, playerColor, &toPoint, putPoint)) {
					reversePointToPoint(toPoint, putPoint, playerColor, &vectorX, &vectorY);
					flagCount++;
				}
			}
		}
	}
	if (flagCount > 0) return true;
	else return false;
}
void Board::checkVector(Point sarchResult, Point putPoint, int *vectorX, int *vectorY)
{
	*vectorX = sarchResult.getX() - putPoint.getX();
	*vectorY = sarchResult.getY() - putPoint.getY();
}

void Board::reversePointToPoint(Point oldPoint, Point putPoint, StoneStatus playerColor, int const * vectorX, int const * vectorY)
{
	int putX = putPoint.getX() + *vectorX;
	int putY = putPoint.getY() + *vectorY;
	while (oldPoint.getX() != putX || oldPoint.getY() != putY) {
		reverceStoneOnBoard(putX, putY);
		printf("REVERSE : ( %d , %d )\n", putX, putY);
		putX += *vectorX;
		putY += *vectorY;
	}
}



bool Board::searchPoint(int *x, int *y, StoneStatus playerColor,Point *toPoint,Point putPoint)
//putPoint����(x,y)������playerColor�ƕʂ̐F�������Ă��邩���������̐�ɓ����F���������ꍇ�͂��̍��W��serchResult�Ɋi�[����
{
	int count = 0;
	Point nowPoint(putPoint.getX(), putPoint.getY());
	nowPoint.incrementPoint(*x, *y);
	for (; nowPoint.getX() >= 0 && nowPoint.getX() <= 7 && nowPoint.getY() >= 0 && nowPoint.getY() <= 7; nowPoint.incrementPoint(*x,*y)) {
		if (getPointColor(nowPoint) == playerColor) {
			if (count > 0) {
				toPoint->setPoint(nowPoint);
				return true;
			}
		}
		else if (getPointColor(nowPoint) != EMPTY && getPointColor(nowPoint) != playerColor) {
			count++;
		}
	}
	return false;
}

bool Board::searchCanPutStone(StoneStatus playerColor, Point *canPutPoint, int *count)
{
	Point *pointTmp = canPutPoint;
	for (int x = 0; x < BOARDSIZE; x++) {
		for (int y = 0; y < BOARDSIZE; y++) {
			Point sarchResult, toPoint,putPoint(x,y);
			for (int searchPointY = y - 1; searchPointY <= y + 1; searchPointY++) {
				for (int searchPointX = x - 1; searchPointX <= x + 1; searchPointX++) {
					int vectorX, vectorY;
					if (searchPointX < 0 || searchPointX > 7 || searchPointY < 0 || searchPointY > 7) continue;
					if (!isEmptyPoint(putPoint)) continue;
					if (getPointColor(searchPointX, searchPointY) != playerColor && getPointColor(searchPointX, searchPointY) != EMPTY) {
						sarchResult = Point(searchPointX, searchPointY);
						checkVector(sarchResult, putPoint, &vectorX, &vectorY);//����������������߂�
						if (searchPoint(&vectorX, &vectorY, playerColor, &toPoint, putPoint)) {
							canPutPoint->setPoint(putPoint);
							canPutPoint++;
							(*count)++;
						}
					}
				}
			}
		}
	}
	if (pointTmp == canPutPoint) return true;
	else return false;
}
