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