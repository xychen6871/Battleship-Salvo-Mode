#include "battleship.h"
#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;

Player::Player() {
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