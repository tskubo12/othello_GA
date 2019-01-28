#include "stdafx.h"
#include "Game.h"


Game::Game() //�Q�[�����n�܂����ۂɌĂяo�����
{
	board_m = Board();//�Q�[���{�[�h�𐶐�����
	player[0] = Player(BLACK);
	player[1] = Player(WHITE);
	std::cout << "player1 : "  ;
	player[0].printPlayerInfo();
	std::cout << "player2 : ";
	player[1].printPlayerInfo();
}


Game::~Game()
{
}

bool Game::nextTurn(Player &nextPlayer,int &passCounter)
{
	board_m.printBoard();
	std::cout << "���̃^�[����" ;
	nextPlayer.printPlayerInfo();

	Point canPutPoint[30];
	int canPutPointCount = 0;
	Color playerColor = nextPlayer.getPlayerColor();
	//���̃v���C���[���΂̂�����ꏊ��\������
	if (board_m.searchCanPutStone(playerColor, canPutPoint, canPutPointCount)) {
		for (int i = 0; i < canPutPointCount; i++) {
			canPutPoint[i].printPoint();
		}	
	}
	else {
		std::cout << "PASS\n";
		passCounter++;
		return true;
	}

	//�΂�u���A�Ԃ̐΂𔽓]����
	int x, y;
	Point point;
	if (nextPlayer.inputPoint(point)) {
		if (point.array_have_thisPoint(canPutPoint, canPutPointCount)) {
			board_m.setStone(point, playerColor);
			board_m.reversePointOnBoard(point, playerColor);
			passCounter = 0;
			return true;
		}
	}
	std::cout << "input Error \"PLEASE RETRY\"\n";
	return false;
}

bool Game::start_game()
{
	int passCounter = 0;
	int player_i,counter = 0;
	while (passCounter != 2) {
		player_i = counter % 2;
		while (!nextTurn(player[player_i],passCounter));
		counter++;
	}
	return false;
}

