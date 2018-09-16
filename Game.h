// CSCI 261 
// 
// Authors: Shu Ee Ong (section E), Landon Walker (section B)
//
// Final Project: Tic Tac Toe - Game declarations

# pragma once

#include <string>
#include "Board.h"

using namespace std;

class Game { 
	private:
	Board playBoard;
	// invalid + valid moves
	int move;
	// only valid moves
	int legitMove;
	
	public:
	Game();
	void startGame(Board playBoard);
	bool gameOver(Board playBoard);
};

