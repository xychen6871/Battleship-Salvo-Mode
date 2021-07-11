#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;
#ifndef BATTLESHIPSALVO
#define BATTLESHIPSALVO

class Player {
public:
	vector<vector<char>> board;
	unordered_map<string,int> status, shipLengths;
	unordered_map<string,char> shipRep;
	int numberOfShots;
	Player();
	~Player();
	void PrintPlayerBoard();
	void PrintPlayerAsEnemy();
	void PlaceShips();
	bool ValidShipPlacement(int i, int j, string ship, bool horizontal);
};

class Battleship {
public:
	Player P1, P2;

	Battleship();
	~Battleship();
	void PrintIntro(); // prints intro
	void Play();
};

#endif