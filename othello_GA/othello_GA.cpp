// othello_GA.cpp : アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"
#include "Game.h"
using namespace std;

void play_the_game();
int main() {
	int i;
	cout << "Let's Play Othello\n" << endl;
	play_the_game();
	cout << "finish \n";
	cin >> i;
}

void play_the_game() {
	Game game = Game();
	game.start_game();
	game.finish_game();
}

