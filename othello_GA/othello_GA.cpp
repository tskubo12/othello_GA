// othello_GA.cpp : アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"
#include "Game.h"
#include<iostream>
using namespace std;

void gameStart();
int main() {
	int i;
	cout << "Let's Play Othello\n" << endl;
	gameStart();
	cin >> i;
}

void gameStart() {
	Game game;
}

