#include "stdafx.h"
#include "Game.h"


Game::Game() //�Q�[�����n�܂����ۂɌĂяo�����
{
	Board board;//�Q�[���{�[�h�𐶐�����
	Player player1 = Player(BLACK);
	Player player2 = Player(WHITE);
	std::cout << "player1 : "  ;
	player1.printPlayerInfo();
	std::cout << "player2 : ";
	player2.printPlayerInfo();
	std::cout << "<�Ֆ�>\n";
	board.printBoard();
}


Game::~Game()
{
}
