#pragma once
#include <iostream>
#include <string>
#define playerN 0
#define player1 1
#define player2 2
using namespace std;
class Player
{
public:
	Player(string n = "Player", int type = player1);
	void increaseWin();
	void increaseLoss();

	int getWin();
	int getLoss();

	int getPlayerType();
	string getName();
	bool operator ==(Player p);
	
private:
	string nom;
	int win;
	int loss;
	int playerType;
};