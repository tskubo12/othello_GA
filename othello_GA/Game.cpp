#include "stdafx.h"
#include "Game.h"


bool Game::playerChoice(int &p,Color color)
{
	std::cout << "-----SELECT PLAYER-----\nHumanPlayer : 1 , AiPlayer : 2 \n";
	if (color == BLACK) {
		std::cout << "BLACK : ";
	}
	else if (color == WHITE) {
		std::cout << "WHITE : ";
	}
	std::cin >> p;
	if (p!= 1 && p != 2) {
		playerChoice(p, color);
		return false;
	}
}

Game::Game() //ゲームが始まった際に呼び出される
{
	board_m = Board();//ゲームボードを生成する
	int playerChoiceNum1 = 0;
	int playerChoiceNum2 = 0;
	//プレイヤーが人間かCPUかを決定する
	shared_ptr<Player> p1, p2;
	playerChoice(playerChoiceNum1, BLACK);
	playerChoice(playerChoiceNum2, WHITE);

	if (playerChoiceNum1 == 1) {
		p1 = make_shared<HumanPlayer>(BLACK);
	}
	else if (playerChoiceNum1 == 2) {
		p1 = make_shared<AiPlayer>(BLACK);
	}

	if (playerChoiceNum2 == 1) {
		p2 = make_shared<HumanPlayer>(WHITE);
	}
	else if (playerChoiceNum2 == 2) {
		p2 = make_shared<AiPlayer>(WHITE);
	}

	player.push_back(p1);
	player.push_back(p2);
	std::cout << "player1 : "  ;
	player[0]->printPlayerInfo();
	std::cout << "player2 : ";
	player[1]->printPlayerInfo();
}


Game::~Game()
{
}

bool Game::nextTurn(std::shared_ptr<Player> nextPlayer,int &passCounter)
{
	board_m.printBoard();
	std::cout << "TURN : " ;
	nextPlayer->printPlayerInfo();

	Color playerColor = nextPlayer->getPlayerColor();

	//そのプレイヤーが石のおける場所を表示する
	if (nextPlayer->createCanPutPointList(board_m)) {
		nextPlayer->printPointList();
	}
	else {
		std::cout << "PASS\n";
		passCounter++;
		return true;
	}

	//石を置き、間の石を反転する
	if (nextPlayer->inputNextPoint()) {
		board_m.setStone(nextPlayer->getNextPoint(), nextPlayer->getPlayerColor());
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

