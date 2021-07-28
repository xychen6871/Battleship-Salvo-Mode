#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;
#ifndef BATTLESHIPSALVO
#define BATTLESHIPSALVO

class Player {
private:
	vector<vector<char>> board;
	unordered_map<char,int> status, shipLengths;
	unordered_map<char,string> shipRep;
	int numberOfShots;
public:
	Player();
	~Player();
	void PrintPlayerBoard();
	void PrintPlayerAsEnemy();
	void PlaceShips();
	bool ValidShipPlacement(int i, int j, char shipChar, bool horizontal);
	bool ValidEnemyAttack(int i, int j);
	int ShotsLeft();
};

class Battleship {
private:
	Player P1, P2;
public:
	Battleship();
	~Battleship();
	void PrintIntro(); // prints intro
	void Play();
	
};

#endif