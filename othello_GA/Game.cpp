#include "stdafx.h"
#include "Game.h"


Game::Game() //ゲームが始まった際に呼び出される
{
	board_m = Board();//ゲームボードを生成する
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
	std::cout << "今のターンは" ;
	nextPlayer.printPlayerInfo();

	Color playerColor = nextPlayer.getPlayerColor();

	//そのプレイヤーが石のおける場所を表示する
	if (nextPlayer.createCanPutPointList(board_m)) {
		nextPlayer.printPointList();
	}
	else {
		std::cout << "PASS\n";
		passCounter++;
		return true;
	}

	//石を置き、間の石を反転する
	Point point;
	if (nextPlayer.inputPoint(point)) {
		if (nextPlayer.list_have_thisPoint(point)) {
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

bool Game::finish_game()
{
	Othello_Score score;
	score.compute_result(board_m);
	board_m.compute_result(score);
	score.print_result();
	return false;
}

