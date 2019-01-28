#include "stdafx.h"
#include "Player.h"


Player::Player(Color color)
{
	playerColor = color;
}

Player::Player()
{
}

Player::~Player()
{
}

void Player::printPlayerInfo() {
	if (playerColor == 1) {
		std::cout << "WHITE(ŒãU)\n";
	}
	else if (playerColor == 2) {
		std::cout << "BLACK(æU)\n";
	}
}

bool Player::canPutStone(Point wantToPutPoint) {
	return false;
}

bool Player::inputPoint(Point &point) {
	int x, y;
	std::cout << "input X : ";
	std::cin >> x;
	std::cout << "input Y : ";
	std::cin >> y;
	
	if (x >= 0 && x < BOARDSIZE && y >= 0 && y < BOARDSIZE)
	{
		point.setPoint(x, y);
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

bool Player::getCanPutPoint(Point putPoint, Point * canPutPointList)
{

	return false;
}
