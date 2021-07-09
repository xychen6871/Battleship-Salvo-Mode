#include "battleship.h"
#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;

Player::Player() {
	numberOfShots = 5;
	board = vector<vector<char>>(10, vector<char>(10, '.'));
	status["Carrier"] = 5;
	status["Battleship"] = 4;
	status["Destroyer"] = 3;
	status["Submarine"] = 3;
	status["PT Boat"] = 2;

	shipLengths["Carrier"] = 5;
	shipLengths["Battleship"] = 4;
	shipLengths["Destroyer"] = 3;
	shipLengths["Submarine"] = 3;
	shipLengths["PT Boat"] = 2;
}

Player::~Player() {
	status.clear();
	shipLengths.clear();
}

void Player::PrintPlayerBoard() {
	// prints the current state of the board to the current player
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cout << board[i][j];
		}
		cout << endl;
	}
}

void Player::PrintPlayerAsEnemy() {
	// prints the current state of the board of the opposing player
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (board[i][j] == '.' || board[i][j] == 'X' || board[i][j] == 'O') {
				cout << board[i][j];
			} else {
				cout << '.';
			}
			
		}
		cout << endl;
	}
}

void Player::PlaceShips() {
	for (auto it = shipLengths.begin(); it != shipLengths.end(); it++) {
		/* bool ValidPlacement = false;
		while (!ValidPlacement) {
			cout << "Place the " << it->first << " on the board\n";
			cout << "Do you want the ship to be placed horizontally (H) or vertically (V)?\n";
		} */
	}
}

Battleship::Battleship() {

}

Battleship::~Battleship() {

}

void Battleship::PrintIntro() {
	cout << "Battleship Salvo Mode:\n";
	cout << "In this game, the number of shots a player can fire depends on the number of ships he or she has left.\n";
	cout << "For example, if a player has 3 ships left, he/she gets to fire 3 shots.\n";
	cout << "The first player to sink the other player's fleet wins.\n";
	cout << "Good luck!\n";
}

int main() {
	return 0;
}