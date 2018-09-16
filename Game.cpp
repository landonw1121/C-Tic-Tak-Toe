// CSCI 261 
// 
// Authors: Shu Ee Ong (section E), Landon Walker (section B)
//
// Final Project: Tic Tac Toe - Game definitions

#include "Game.h"
#include "Board.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

Game::Game() {
} 

void Game::startGame(Board playBoard) { 
	// game keeps going when no winning conditions are met and boxes are not all filled up
	cout << "Welcome to Tic Tac Toe! Play with a buddy and see who wins! Enter an integer 1 - 9 for your turn. Good luck!" << endl;
	
	// vector of already played numbers;
	vector<int> playedNums;
	move = 0;
	legitMove = 0;
	
	while(!gameOver(playBoard)) { 
		playBoard.printUpdatedBoard(); 
		int chosenBox; 

		
		// starts with player 1's turn
		if (move % 2 == 0) {
			cout << "Player 1, it's your move: ";
			cin >> chosenBox; 
			// Makes sure that the input is within 1 and 9 inclusive and has not been played before.
			if (chosenBox < 1 || chosenBox > 9 || playBoard.playedBefore(chosenBox, playedNums) == true) {
				// allows one more try if invalid input, if input is invalid again, then player loses move. 
				cout << "Invalid move. You have one more try: ";
				cin >> chosenBox;
				// if input is invalid again:
				if (chosenBox < 1 || chosenBox > 9 || playBoard.playedBefore(chosenBox, playedNums) == true) {
					cout << "Invalid move." << endl;
					move++;
					continue;
				}
				playBoard.subtLabel(playBoard.getPlayer1Symbol(), chosenBox); 
			}
			// if input is valid, then subtitute chosen box number with player symbol
			else {
				playBoard.subtLabel(playBoard.getPlayer1Symbol(), chosenBox); 
			}
			playedNums.push_back(chosenBox);
		}
		
		// player 2's turn
		else { 
			cout << "Player 2, it's your move: ";
			cin >> chosenBox;
			if (chosenBox < 1 || chosenBox > 9 || playBoard.playedBefore(chosenBox, playedNums) == true) {
				cout << "Invalid move. You have one more try: ";
				cin >> chosenBox;
				if (chosenBox < 1 || chosenBox > 9 || playBoard.playedBefore(chosenBox, playedNums) == true) {
					cout << "Invalid move." << endl;
					move++;
					continue;
				}
				playBoard.subtLabel(playBoard.getPlayer2Symbol(), chosenBox); 
			}
			else {
				playBoard.subtLabel(playBoard.getPlayer2Symbol(), chosenBox);
			}
			playedNums.push_back(chosenBox);
		}
		// increases move after each turn, only legitMove is increased when move is valid; invalid moves continued on to next round without increasing legitMove
		move++;
		legitMove++;
	}
	
	// prints final winning board
	playBoard.printUpdatedBoard();
	// writes winning board to winner.txt
	playBoard.writeToFile();

	// function for player1 winning
	// %2 is for even moves and <= 9 is the max number of moves
	if (move % 2 != 0 && legitMove < 9) {
		cout << "Player 1 wins! Congratulations player 1!" << endl;
	}
	// determines if player2 is the winner	
	else if (move % 2 == 0 && legitMove < 9) { 
		cout << "Player 2 wins! Congratulations player 2!" << endl;	
	}
	else {
		cout << "It's a tie!" << endl;
	}
	
}

// checks for conditions where game is done
bool Game::gameOver(Board playBoard) {
	if (playBoard.win() == true) {
		return true; 
	}
	else if (legitMove >= 9) {
		return true;
	}
	else {
		return false;
	}
}

