#pragma once
#include<iostream>
#include<vector>
#include<memory>
#define BOARDSIZE 4 
using namespace std;

enum Color {
	EMPTY = 0,
	WHITE = 1,
	BLACK = 2,
};

enum PlayerType {
	HUMAN = 0,
	CPU = 1,
};