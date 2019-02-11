#include "stdafx.h"
#include "Player.h"


Player::Player(Color color)
{
	playerColor = color;
}
Player::Player()
{
	playerColor = EMPTY;

}

bool Player::createCanPutPointList(Board &board)
{
	canPutPointList.clear();
	//ç∂è„(0,0)Ç©ÇÁ(0,1),(0,2)....(7,7)Ç∆å©ÇƒÇ¢Ç≠
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



void Player::printPlayerInfo() {
	if (type == CPU) std::cout << " CPU \n";
	else if (type == HUMAN) std::cout << " HUMAN \n";

	if (playerColor == 1) {
		std::cout << "WHITE(å„çU)\n";
	}
	else if (playerColor == 2) {
		std::cout << "BLACK(êÊçU)\n";
	}
}

void Player::printPointList()
{
	for (auto i = canPutPointList.begin(); i != canPutPointList.end(); i++) {
		i->printPoint();
	}
}






Color Player::getPlayerColor()
{
	return playerColor;
}

Point Player::getNextPoint()
{
	return nextPoint;
}

PlayerType Player::getPlayerType()
{
	return type;
}
