#include "stdafx.h"
#include "Player.h"


Player::Player(StoneStatus color)
{
	playerColor = color;
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

Point Player::inputPoint() {
	int x, y;
	std::cout << "input X : ";
	std::cin >> x;
	std::cout << "input Y : ";
	std::cin >> y;
	nextPoint = Point(x, y);

	return nextPoint;
	
}

StoneStatus Player::getPlayerColor()
{
	return playerColor;
}
