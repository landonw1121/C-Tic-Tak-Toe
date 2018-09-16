// CSCI 261 
// 
// Authors: Shu Ee Ong (section E), Landon Walker (section B)
//
// Final Project: Tic Tac Toe

#include <iostream>
#include "Board.h"
#include "Game.h"
using namespace std;

#include <fstream>

int main() {

	Board playingBoard; 

	Game game;

	game.startGame(playingBoard);
	
	return 0;
}