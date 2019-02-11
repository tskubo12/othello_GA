#include "stdafx.h"
#include "AiPlayer.h"


AiPlayer::AiPlayer(Color color):Player(color)
{
	type = CPU;
}


AiPlayer::~AiPlayer()
{
}

bool AiPlayer::inputNextPoint() {
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_int_distribution<> rand(0, canPutPointList.size() -1);
	auto result = rand(mt);
	if (nextPoint.setPoint(canPutPointList[result]) && (list_have_thisPoint(nextPoint)))
	{
		return true;
	}
	else {
		return false;
	}

}
