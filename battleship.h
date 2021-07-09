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
	int numberOfShots;
	Player();
	~Player();
	void PrintPlayerBoard();
	void PrintPlayerAsEnemy();
	void PlaceShips();
};

class Battleship {
public:
	Player P1, P2;

	Battleship();
	~Battleship();
	void PrintIntro(); // prints intro
};

#endif