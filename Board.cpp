// CSCI 261 
// 
// Authors: Shu Ee Ong (section E), Landon Walker (section B)
//
// Final Project: Tic Tac Toe - Board definitions

#include "Board.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

// Default case
Board :: Board() {
	player1Symbol = 'X';
	player2Symbol = 'O';
}

// Sets player symbols
void Board :: setBoard (char _player1Symbol, char _player2Symbol) {
	player1Symbol = _player1Symbol;
	player2Symbol = _player2Symbol;
}

// function that updates board after every round
void Board :: printUpdatedBoard(){
	for (int i=0; i < 3; i++){
		for (int j=0; j < 3; j++){
			cout << "[" << label[(3 * i) + j];
			cout << "]";
		}
		cout << endl;
	}
}

// function to subtitute board label with player symbol
void Board :: subtLabel(char playerSymbol, char boxLabel) {
	label[boxLabel - 1] = playerSymbol; 
}

// function that checks all winning conditions and returns if true
bool Board :: win() {
	// row 1
	if (label[0] == label[1] && label[1] == label[2]) {
		return true;
	}
	// row 2
	else if (label[3] == label[4] && label[4] == label[5]) {
		return true; 
	}
	// row 3
	else if (label[6] == label[7] && label[7] == label[8]) {
		return true; 
	}
	// column 1
	else if (label[0] == label[3] && label[3] == label[6]) {
		return true; 
	}
	// column 2
	else if (label[1] == label[4] && label[4] == label[7]) {
		return true; 
	}
	// column 3
	else if (label[2] == label[5] && label[5] == label[8]) {
		return true; 
	}
	// diagonal from top left to bottom right
	else if (label[0] == label[4] && label[4] == label[8]) {
		return true; 
	}
	// diagonal from top right to bottom left
	else if (label[2] == label[4] && label[4] == label[6]) {
		return true; 
	}
	// no winning condition
	else {
		return false;
	}
}

// function to check if that spot has already been played
bool Board :: isSpaceUsed(int boxLabel){
	if ( label[boxLabel] == getPlayer1Symbol()){
		return true;
	}
	else if ( label[boxLabel] == getPlayer2Symbol()){
		return true;
	}
	else{
		return false;
	}
}

// function to check if number has been chosen before
bool Board :: playedBefore(int numChosen, vector<int> v) {
	for (int i = 0; i < v.size(); ++i) {
		if (numChosen == v.at(i)) {
			return true;
		}
	}
	return false;
}

char Board::getPlayer1Symbol() {
	return player1Symbol;
}

char Board::getPlayer2Symbol() {
	return player2Symbol;
}

// function that writes file to winner.txt
void Board :: writeToFile(){
	ofstream winner;
	winner.open("winner.txt");
	
	if (winner.fail()) {
        cout << "Error opening output file";
    }
    
	for (int i=0; i < 3; i++){
		for (int j=0; j < 3; j++){
			winner << "[" << label[(3 * i) + j];
			winner << "]";
		}
		winner << endl;
	}
}