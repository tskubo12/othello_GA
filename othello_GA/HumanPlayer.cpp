#include "stdafx.h"
#include "HumanPlayer.h"


HumanPlayer::HumanPlayer(Color color):Player(color)
{
	type = HUMAN;
}


HumanPlayer::~HumanPlayer()
{
}

//�v���C���[�����΂�u�������ꏊ����͂����ꂪ�u����ꏊ�ł��邩�`�F�b�N����
//�s�\�ȏꍇ��false��Ԃ�
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
