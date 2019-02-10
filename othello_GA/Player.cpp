#include "stdafx.h"
#include "Player.h"


Player::Player(Color color)
{
	playerColor = color;
}

bool Player::createCanPutPointList(Board &board)
{
	canPutPointList.clear();
	//����(0,0)����(0,1),(0,2)....(7,7)�ƌ��Ă���
	for (int x = 0; x < BOARDSIZE; x++) {
		for (int y = 0; y < BOARDSIZE; y++) {
			Point want_to_putPoint(x, y);

			if (board.canReversePointOnBoard(want_to_putPoint, playerColor)) {
				canPutPointList.push_back(want_to_putPoint);
			}
		}
	}
	if (canPutPointList.empty()) return false;
	else return true;
}

bool Player::list_have_thisPoint(Point point)
{
	for (auto i = canPutPointList.begin(); i != canPutPointList.end(); i++) {
		if (point == *i) return true;
	}
	return false;
}

Player::Player()
{
}

void Player::printPlayerInfo() {
	if (playerColor == 1) {
		std::cout << "WHITE(��U)\n";
	}
	else if (playerColor == 2) {
		std::cout << "BLACK(��U)\n";
	}
}

void Player::printPointList()
{
	for (auto i = canPutPointList.begin(); i != canPutPointList.end(); i++) {
		i->printPoint();
	}
}


bool Player::inputPoint(Point &point) {
	int x, y;
	std::cout << "input X : ";
	std::cin >> x;
	std::cout << "input Y : ";
	std::cin >> y;
	
	if (point.setPoint(x,y))
	{
		return true;
	}
	else {
		return false;
	} 
	
}

//�v���C���[�����΂�u�������ꏊ����͂���
bool Player::inputNextPoint() {
	int x, y;
	std::cout << "input X : ";
	std::cin >> x;
	std::cout << "input Y : ";
	std::cin >> y;

	if (nextPoint.setPoint(x,y))
	{
		return true;
	}
	else {
		return false;
	}

}


Color Player::getPlayerColor()
{
	return playerColor;
}
