#include "battleship.h"
#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;

Player::Player() {
	numberOfShots = 5;
	board = vector<vector<char>>(10, vector<char>(10, '.'));
	status['C'] = 5;
	status['B'] = 4;
	status['D'] = 3;
	status['S'] = 3;
	status['P'] = 2;

	shipLengths['C'] = 5;
	shipLengths['B'] = 4;
	shipLengths['D'] = 3;
	shipLengths['S'] = 3;
	shipLengths['P'] = 2;

	shipRep['C'] = "Carrier";
	shipRep['B'] = "Battleship";
	shipRep['D'] = "Destroyer";
	shipRep['S'] = "Submarine";
	shipRep['P'] = "PT Boat";
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
			cout << "Place the " << shipRep[it->first] << " on the board\n";
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

bool Player::ValidShipPlacement(int i, int j, char shipChar, bool horizontal) {
	if (i < 0 || i >= 10 || j < 0 || j >= 10) {
		return false; // coordinate of starting point is invalid --> return false
	}

	for (int x = 0; x < shipLengths[shipChar]; x++) {
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
 	for (int x = 0; x < shipLengths[shipChar]; x++) {
		if (horizontal) {
			board[i][j + x] = shipChar;
		} else {
			board[i + x][j] = shipChar;
		}
	}
	return true;
}

bool Player::ValidEnemyAttack(int i, int j) {
	// invalid coordinate or coordinate has already been attacked
	if (i < 0 || i >= 10 || j < 0 || j >= 10 || board[i][j] == 'X' || board[i][j] == 'O') {
		cout << "Invalid shot! Try again!\n";
		return false;
	}

	if (board[i][j] == '.') {
		// Shot has missed
		cout << "Miss!\n";
		board[i][j] == 'X';
	} else {
		// The attacker has landed a direct hit
		char c = board[i][j];
		cout << "Enemy " << shipRep[c] << " has been hit!\n";
		board[i][j] = 'O';
		status[c]--;
		if (status[c] <= 0) {
			status[c] = 0;
			cout << "Enemy " << shipRep[c] << " has been sunk!\n";
			numberOfShots--;
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
			cout << "Player 1, it is your turn.\n";
			cout << "Your board:\n";
			P1.PrintPlayerBoard();
			cout << endl;
			cout << "Your opponent's board:\n";
			P2.PrintPlayerAsEnemy();
			cout << endl;

			int shotsLeft = P1.numberOfShots;
			for (int i = 0; i < shotsLeft; i++) {
				bool validShot = false;
				while (!validShot) {
					cout << "Player 1, choose a coordinate to fire on (row, col)?\n";
					int i, j;
					cin >> i >> j;

					// Player 1 attacks Player 2

					cout << "Your board:\n";
					P1.PrintPlayerBoard();
					cout << endl;
					cout << "Your opponent's board:\n";
					P2.PrintPlayerAsEnemy();
					cout << endl;
				}
			}
		} else {
			// Player 2's turn
			cout << "Player 2, it is your turn.\n";
			cout << "Your board:\n";
			P2.PrintPlayerBoard();
			cout << endl;
			cout << "Your opponent's board:\n";
			P1.PrintPlayerAsEnemy();
			cout << endl;

			int shotsLeft = P2.numberOfShots;
			for (int i = 0; i < shotsLeft; i++) {
				bool validShot = false;
				while (!validShot) {
					cout << "Player 2, choose a coordinate to fire on (row, col)?\n";
					int i, j;
					cin >> i >> j;

					// Player 2 attacks Player 1

					cout << "Your board:\n";
					P2.PrintPlayerBoard();
					cout << endl;
					cout << "Your opponent's board:\n";
					P1.PrintPlayerAsEnemy();
					cout << endl;
				}
			}
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
	game.PrintIntro();

	game.P1.PlaceShips();
	return 0;
}