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

bool Board::is_point_in_board(Point want_to_put)
{
	if (want_to_put.getX() < 0 || want_to_put.getY() < 0 || want_to_put.getX() > BOARDSIZE - 1 || want_to_put.getY() > BOARDSIZE - 1) {
		return false;
	}
	else {
		return true;
	}
}

/*指定した座標(checkPoint)がplayerColorの逆の色であるかどうか()
例えば、playerColorが白の場合、checkPointが黒であればtrueを返す
*/
bool Board::point_have_enemyStone(Point checkPoint,Color playerColor)

{
	if(getPointColor(checkPoint) != playerColor && getPointColor(checkPoint) != EMPTY)
		return true;
	else return false;
}

Board::Board()//ゲーム開始時のボードの状況
{
	stoneOnBoard[BOARDSIZE / 2 - 1][BOARDSIZE / 2 - 1].setStoneColor(WHITE);
	stoneOnBoard[BOARDSIZE / 2][BOARDSIZE / 2].setStoneColor(WHITE);
	stoneOnBoard[BOARDSIZE / 2][BOARDSIZE / 2 - 1].setStoneColor(BLACK);
	stoneOnBoard[BOARDSIZE / 2 - 1][BOARDSIZE / 2].setStoneColor(BLACK);
}


Board::~Board()
{
}

//ボードの状況をプリントする
void Board::printBoard() {
	int a;
	std::cout << "　";
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
				std::cout << "□";
				break;
			case BLACK:
				std::cout << "黒";
				break;
			case WHITE:
				std::cout << "白";
				break;
			default:
				std::cout << "E";
				break;
			}
		}
		std::cout << "\n";
	}
		
}



//指定したpointにplayerColor色の石を置く
void Board::setStone(Point point,Color playerColor)
{
	stoneOnBoard[point.getY()][point.getX()].setStoneColor(playerColor);
}



//指定したpoint上にある石の色(StoneStatus)を返す
Color Board::getPointColor(Point point)
{
	return stoneOnBoard[point.getY()][point.getX()].getStoneColor();
}

Color Board::getPointColor(int x, int y)
{

	return stoneOnBoard[y][x].getStoneColor();
}


//指定したpoint上にある石を反転させる
void Board::reverceStoneOnBoard(int x, int y)
{
	stoneOnBoard[y][x].reverseStone();
}

void Board::reverceStoneOnBoard(Point point)
{
	reverceStoneOnBoard(point.getX(), point.getY());
}


//指定した座標にまだ石が置かれていないか
bool Board::isEmptyPoint(Point point){
	if (getPointColor(point) == EMPTY) {
		return true;
	}
	else {
		return false;
	}
}


//指定したpointにplayerColorの石は置くことができるか
bool Board::canReversePointOnBoard(Point want_to_put,Color playerColor){
	int flagCount = 0;
	int const x = want_to_put.getX();
	int const y = want_to_put.getY();
	Point searchPoint,toPoint;

	if (!isEmptyPoint(want_to_put)) return false;

	//want_to_putの左上から真上、右上、左....右下の順番でsearchResultに格納されていく
	for(int searchPointY =y - 1;searchPointY <= y + 1;searchPointY++){
		for (int searchPointX = x - 1; searchPointX <= x + 1; searchPointX++) {
			int vectorX, vectorY;
			searchPoint.setPoint(searchPointX, searchPointY);

			/*座標(searchPointX,searchPointY)が盤外や空白を指したとき検索を行わない*/
			if (!is_point_in_board(searchPoint)) continue;
			if (isEmptyPoint(searchPoint)) continue;

			
			if (point_have_enemyStone(searchPoint,playerColor)) {
				int vectorX;
				int vectorY;
				setVector(want_to_put, searchPoint, vectorX, vectorY);
				if (can_reach_myStonePoint(vectorX, vectorY, playerColor, toPoint, want_to_put)) {
					return true;
				}
			}
		}
	}
	return false;
}


//指定したpointからひっくり返せる石の座標を返す
void Board::reversePointOnBoard(Point putPoint, Color playerColor){
/*
	int flagCount = 0;
	//putPoint座標の周りの検索を行う
	int const x = putPoint.getX();
	int const y = putPoint.getY();
	Point sarchResult, toPoint;
	for (int searchPointY = y - 1; searchPointY <= y + 1; searchPointY++) {
		for (int searchPointX = x - 1; searchPointX <= x + 1; searchPointX++) {
			int vectorX, vectorY;
			if (searchPointX < 0 || searchPointX > 7 || searchPointY < 0 || searchPointY > 7) continue;
			if (getPointColor(searchPointX, searchPointY) != playerColor && getPointColor(searchPointX, searchPointY) != EMPTY) {
				sarchResult = Point(searchPointX, searchPointY);
				checkVector(sarchResult, putPoint, &vectorX, &vectorY);//検索する方向を決める

				if (can_reach_myStonePoint(&vectorX, &vectorY, playerColor, &toPoint, putPoint)) {
					reversePointToPoint(toPoint, putPoint, playerColor, &vectorX, &vectorY);
					flagCount++;
				}
			}
		}
	}
*/
	//9方向への検索を行う
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
void Board::checkVector(Point sarchResult, Point putPoint, int *vectorX, int *vectorY)
{
	*vectorX = sarchResult.getX() - putPoint.getX();
	*vectorY = sarchResult.getY() - putPoint.getY();
}

//
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

void Board::reversePointToPoint(Point oldPoint, Point putPoint, Color)
{
	int vectorX, vectorY;
	int diffX = putPoint.getX() - oldPoint.getX();
	int diffY = putPoint.getY() - oldPoint.getY();
	setVector(diffX ,vectorX);
	setVector(diffY, vectorY);


}



//putPointから(x,y)方向へplayerColorと別の色が続いているか検索しその先に同じ色があった場合はその座標をtoPointに格納する
bool Board::can_reach_myStonePoint(int const&x, int const&y, Color playerColor,Point &toPoint,Point &putPoint)
{
	int count = 0;
	Point nowPoint(putPoint.getX(), putPoint.getY());
	nowPoint.incrementPoint(x, y);
	for (;is_point_in_board(nowPoint); nowPoint.incrementPoint(x,y)) {
		if (isEmptyPoint(nowPoint)) continue;
		if (getPointColor(nowPoint) == playerColor) {
			if (count > 0) {
				toPoint.setPoint(nowPoint);
				return true;
			}
		}
		else if (point_have_enemyStone(nowPoint,playerColor)) {
			count++;
		}
	}
	return false;
}



/*石のおくことのできる座標を全てcanPutPoint配列に格納する*/
bool Board::searchCanPutStone(Color playerColor, Point *canPutPoint, int &count)
{
	Point *pointTmp = canPutPoint;


	//左上(0,0)から(0,1),(0,2)....(7,7)と見ていく
	for (int x = 0; x < BOARDSIZE; x++) {
		for (int y = 0; y < BOARDSIZE; y++) {
			Point want_to_putPoint(x, y);
			
			if (canReversePointOnBoard(want_to_putPoint, playerColor)) {
				canPutPoint->setPoint(want_to_putPoint);
				canPutPoint++;
				count++;
			}
		}
	}

	if (pointTmp != canPutPoint) return true;
	else return false;
}
