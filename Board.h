// CSCI 261 
// 
// Authors: Shu Ee Ong (section E), Landon Walker (section B)
//
// Final Project: Tic Tac Toe - Board declarations

#pragma once

#include <string>
#include <fstream>
#include <vector>

using namespace std;

class Board {
	private:
	// box labels
	char label[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
	char player1Symbol;
	char player2Symbol;

	public: 
	//default board
	Board();
	// board with parameters
	void setBoard(char _player1Symbol, char _player2Symbol); 
	// function that updates board after every round
	void printUpdatedBoard();
	// function that substitutes box label with player symbol
	void subtLabel(char playerSymbol, char boxLabel);
	// function that checks for winning condition
	bool win();
	// function that checks if a space has already been played
	bool isSpaceUsed(int boxLabel);
	// function to check if number has been chosen before
	bool playedBefore(int numChosen, vector<int> v);
	char getPlayer1Symbol();
	char getPlayer2Symbol();
	// function that writes the winning board to winner.txt
	void writeToFile();

	
};

