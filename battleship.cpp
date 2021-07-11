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

	shipRep["Carrier"] = 'C';
	shipRep["Battleship"] = 'B';
	shipRep["Destroyer"] = 'D';
	shipRep["Submarine"] = 'S';
	shipRep["PT Boat"] = 'P';
}

Player::~Player() {
	status.clear();
	shipLengths.clear();
	shipRep.clear();
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
		bool ValidPlacement = false;
		while (!ValidPlacement) {
			PrintPlayerBoard();
			cout << "Place the " << it->first << " on the board\n";
			cout << "Do you want the ship to be placed horizontally (1)? If not, the ship will be placed vertically (0).\n";
			int horizontal;
			cin >> horizontal; // 1 --> ship placed horizontally, 0 --> ship placed vertically


			int x, y;
			cout << "Please select a position (row,col) to place the ship.\n";
			cin >> x >> y;

			bool isHorizontal = (horizontal == 0) ? false : true;
			ValidPlacement = ValidShipPlacement(x, y, it->first, isHorizontal);
			if (!ValidPlacement) {
				cout << "Invalid ship placement! Try again!\n";
			}
		} 
	}
	PrintPlayerBoard();
	cout << "Ship deployment has been completed.\n";
}

bool Player::ValidShipPlacement(int i, int j, string ship, bool horizontal) {
	if (i < 0 || i >= 10 || j < 0 || j >= 10) {
		return false; // coordinate of starting point is invalid --> return false
	}

	for (int x = 0; x < shipLengths[ship]; x++) {
		if (horizontal) { // check for invalid index access
			if (j + x >= 10 || board[i][j + x] != '.') {
				return false;
			}
		} else {
			if (i + x >= 10 || board[i + x][j] != '.') {
				return false;
			}
		}
	}
	// place the ship and return true
 	for (int x = 0; x < shipLengths[ship]; x++) {
		if (horizontal) {
			board[i][j + x] = shipRep[ship];
		} else {
			board[i + x][j] = shipRep[ship];
		}
	}
	return true;
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

void Battleship::Play() {
	PrintIntro();
	cout << "Player 1, place your ships. Player 2, look away!\n";
	P1.PlaceShips();
	cout << "Player 2, place your ships. Player 1, look away!\n";
	P2.PlaceShips();
	int turn = 0; // 0 --> Player 1's turn, 1 --> Player 2's turn
	while (P1.numberOfShots > 0 && P2.numberOfShots) {
		if (turn == 0) {
			// Player 1's turn
		} else {
			// Player 2's turn
		}
		turn++;
		turn %= 2;
	}

	if (P2.numberOfShots == 0) {
		cout << "Player 2 won!\n";
	} else {
		cout << "Player 1 won!\n";
	}
}

int main() {
	Battleship game;
	//game.PrintIntro();

	//game.P1.PlaceShips();
	return 0;
}