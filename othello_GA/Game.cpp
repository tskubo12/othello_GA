#include "stdafx.h"
#include "Game.h"


Game::Game() //ゲームが始まった際に呼び出される
{
	Board board;//ゲームボードを生成する
	Player player1 = Player(BLACK);
	Player player2 = Player(WHITE);
	std::cout << "player1 : "  ;
	player1.printPlayerInfo();
	std::cout << "player2 : ";
	player2.printPlayerInfo();
	std::cout << "<盤面>\n";
	board.printBoard();
}


Game::~Game()
{
}
