#include "stdafx.h"
#include "Game.h"


Game::Game() //ゲームが始まった際に呼び出される
{
	bool flag = true;
	board_m = Board();//ゲームボードを生成する
	Player player1 = Player(BLACK);
	Player player2 = Player(WHITE);
	Player *p;
	std::cout << "player1 : "  ;
	player1.printPlayerInfo();
	std::cout << "player2 : ";
	player2.printPlayerInfo();
	std::cout << "<盤面>\n";
	board_m.printBoard();
	while (true) {
		std::cout << "\n次の番 : "; 
		player1.printPlayerInfo();
		flag = nextTurn(&player1);
		if (!flag) {
			while (!(flag = nextTurn(&player1)));
		}
		board_m.printBoard();
		std::cout << "次の番 : ";
		player2.printPlayerInfo();
		flag = nextTurn(&player2);
		if (!flag) {
			while (!(flag = nextTurn(&player2)));
		}
		board_m.printBoard();
	}
}


Game::~Game()
{
}

bool Game::nextTurn(Player *nextPlayer)
{
	Point point = nextPlayer->inputPoint();

	if (board_m.isEmptyPoint(point) && board_m.reversePointOnBoard(point,nextPlayer->getPlayerColor())){
		board_m.setStone(point, nextPlayer->getPlayerColor());
		return true;
	}
	else {
		std::cout << "input Error \nPLEASE RETRY\n";
		return false;
	}
}

