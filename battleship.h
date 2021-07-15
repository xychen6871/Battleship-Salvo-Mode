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
	unordered_map<char,int> status, shipLengths;
	unordered_map<char,string> shipRep;
	int numberOfShots;
	Player();
	~Player();
	void PrintPlayerBoard();
	void PrintPlayerAsEnemy();
	void PlaceShips();
	bool ValidShipPlacement(int i, int j, char shipChar, bool horizontal);
	bool ValidEnemyAttack(int i, int j);
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