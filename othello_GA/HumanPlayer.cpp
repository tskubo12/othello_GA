#include "stdafx.h"
#include "HumanPlayer.h"


HumanPlayer::HumanPlayer(Color color):Player(color)
{
	type = HUMAN;
}


HumanPlayer::~HumanPlayer()
{
}

//プレイヤーが次石を置きたい場所を入力しそれが置ける場所であるかチェックする
//不可能な場合はfalseを返す
bool HumanPlayer::inputNextPoint()
{
	int x, y;
	std::cout << "input X : ";
	std::cin >> x;
	std::cout << "input Y : ";
	std::cin >> y;

	if (nextPoint.setPoint(x, y) && (list_have_thisPoint(nextPoint)))
	{
		return true;
	}
	else {
		return false;
	}

}
