#include "stdafx.h"
#include "Board.h"


void Board::setVector(int& diff,int& vector)
{
	
	if (diff > 0) vector = -1;
	else if (diff < 0) vector = 1;
	else vector = 0;

}

void Board::setVector(Point &want_to_checkPoint,Point &already_put_point,int &vectorX,int &vectorY)
{
	int diffX = want_to_checkPoint.getX() - already_put_point.getX();
	int diffY = want_to_checkPoint.getY() - already_put_point.getY();

	setVector(diffX, vectorX);
	setVector(diffY, vectorY);
}


/*�w�肵�����W(checkPoint)��playerColor�̋t�̐F�ł��邩�ǂ���()
�Ⴆ�΁AplayerColor�����̏ꍇ�AcheckPoint�����ł����true��Ԃ�
*/
bool Board::point_have_enemyStone(Point checkPoint,Color playerColor)

{
	if(getPointColor(checkPoint) != playerColor && getPointColor(checkPoint) != EMPTY)
		return true;
	else return false;
}

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

//�{�[�h�̏󋵂��v�����g����
void Board::printBoard() {
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



//�w�肵��point��playerColor�F�̐΂�u��
void Board::setStone(Point point,Color playerColor)
{
	stoneOnBoard[point.getY()][point.getX()].setStoneColor(playerColor);
}



//�w�肵��point��ɂ���΂̐F(StoneStatus)��Ԃ�
Color Board::getPointColor(Point point)
{
	return stoneOnBoard[point.getY()][point.getX()].getStoneColor();
}


//�w�肵��point��ɂ���΂𔽓]������
void Board::reverceStoneOnBoard(int x, int y)
{
	stoneOnBoard[y][x].reverseStone();
}

//�w�肵�����W�ɂ܂��΂��u����Ă��Ȃ���
bool Board::isEmptyPoint(Point point){
	if (getPointColor(point) == EMPTY) {
		return true;
	}
	else {
		return false;
	}
}


//�w�肵��point��playerColor�̐΂͒u�����Ƃ��ł��邩
bool Board::canReversePointOnBoard(Point want_to_put,Color playerColor){
	int flagCount = 0;
	int const x = want_to_put.getX();
	int const y = want_to_put.getY();
	Point searchPoint,toPoint;

	if (!isEmptyPoint(want_to_put)) return false;

	//want_to_put�̍��ォ��^��A�E��A��....�E���̏��Ԃ�searchResult�Ɋi�[����Ă���
	for(int searchPointY =y - 1;searchPointY <= y + 1;searchPointY++){
		for (int searchPointX = x - 1; searchPointX <= x + 1; searchPointX++) {
			if (searchPoint.setPoint(searchPointX, searchPointY)) {
				if (isEmptyPoint(searchPoint)) continue;
				if (point_have_enemyStone(searchPoint, playerColor)) {
					int vectorX;
					int vectorY;
					setVector(want_to_put, searchPoint, vectorX, vectorY);
					if (can_reach_myStonePoint(vectorX, vectorY, playerColor, toPoint, want_to_put)) {
						return true;
					}
				}
			}
			else {
				continue;
			}
			/*���W(searchPointX,searchPointY)���ՊO��󔒂��w�����Ƃ��������s��Ȃ�*/
			//if (!is_point_in_board(searchPoint)) continue;
			//if (isEmptyPoint(searchPoint)) continue;
		}
	}
	return false;
}


//�w�肵��point����Ђ�����Ԃ���΂̍��W��Ԃ�
void Board::reversePointOnBoard(Point putPoint, Color playerColor){
	//9�����ւ̌������s��
	int vectorX, vectorY;
	Point reachedPoint;
	for (vectorX = -1; vectorX <= 1; vectorX++) {
		for (vectorY = -1; vectorY <= 1; vectorY++) {
			if (vectorX == 0 && vectorY == 0) continue;
			if (can_reach_myStonePoint(vectorX, vectorY, playerColor, reachedPoint, putPoint))
				reversePointToPoint(reachedPoint, putPoint, playerColor ,vectorX, vectorY);
		}
	}
}

//void Board::compute_result(Othello_Score &score)
//{
//	int rowNum, columNum;
//	for (rowNum = 0; rowNum < BOARDSIZE; rowNum++) {
//		for (columNum = 0; columNum < BOARDSIZE; columNum++) {
//			Point point(columNum, rowNum);
//			score.score_add(getPointColor(point));
//		}
//	}
//}


void Board::reversePointToPoint(Point oldPoint, Point putPoint, Color playerColor, int const &vectorX, int const &vectorY)
{
	int putX = putPoint.getX() + vectorX;
	int putY = putPoint.getY() + vectorY;
	while (oldPoint.getX() != putX || oldPoint.getY() != putY) {
		reverceStoneOnBoard(putX, putY);
		printf("REVERSE : ( %d , %d )\n", putX, putY);
		putX += vectorX;
		putY += vectorY;
	}
}


//putPoint����(x,y)������playerColor�ƕʂ̐F�������Ă��邩���������̐�ɓ����F���������ꍇ�͂��̍��W��toPoint�Ɋi�[����
bool Board::can_reach_myStonePoint(int const&x, int const&y, Color playerColor,Point &toPoint,Point &putPoint)
{
	int count = 0;
	Point nowPoint(putPoint.getX(), putPoint.getY());
	while(nowPoint.incrementPoint(x,y) == true){
		if (isEmptyPoint(nowPoint)) break;//continue;
		if (getPointColor(nowPoint) == playerColor) {
			if (count > 0) {
				toPoint.setPoint(nowPoint);
				toPoint = nowPoint;
				return true;
			}
		}
		else if (point_have_enemyStone(nowPoint,playerColor)) {
			count++;
		}
	}
	return false;
}

