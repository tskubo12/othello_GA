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

	Color playerColor = nextPlayer.getPlayerColor();

	//���̃v���C���[���΂̂�����ꏊ��\������
	if (nextPlayer.createCanPutPointList(board_m)) {
		nextPlayer.printPointList();
	}
	else {
		std::cout << "PASS\n";
		passCounter++;
		return true;
	}

	//�΂�u���A�Ԃ̐΂𔽓]����
	if (nextPlayer.inputNextPoint()) {
		board_m.setStone(nextPlayer.getNextPoint(), nextPlayer.getPlayerColor());
		passCounter = 0;
		return true;
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

void Game::finish_game()
{
	Othello_Score score;
	score.compute_result(board_m);
	score.print_result();
}

