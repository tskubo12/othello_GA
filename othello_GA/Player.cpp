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
		std::cout << "WHITE(��U)\n";
	}
	else if (playerColor == 2) {
		std::cout << "BLACK(��U)\n";
	}
}