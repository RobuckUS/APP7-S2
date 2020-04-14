#include "Player.h"
Player::Player(string n, int type)
{
	nom = n;
	win = 0;
	loss = 0;
	playerType = type;
}

void Player::increaseWin()
{
	win++;
}

void Player::increaseLoss()
{
	loss++;
}

int Player::getWin()
{
	return win;
}

int Player::getLoss()
{
	return loss;
}

int Player::getPlayerType()
{
	return playerType;
}

string Player::getName()
{
	return nom;
}

bool Player::operator==(Player p)
{
	if (nom == p.getName() && playerType == p.getPlayerType())
		return true;
	
	else
		return false;
}
