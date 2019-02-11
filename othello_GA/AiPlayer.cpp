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

	if (nextPoint.setPoint(canPutPointList[0]) && (list_have_thisPoint(nextPoint)))
	{
		return true;
	}
	else {
		return false;
	}

}
