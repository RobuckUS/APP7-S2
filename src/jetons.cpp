#include "jetons.h"

Jetons::Jetons()
{
}

Jetons::Jetons(int x, int y, int r, Player p) : QGraphicsEllipseItem(x, y, r, r)
{
	rayon = r;
	player = p;
	if (player.getPlayerType() == playerN)
	{
		setBrush(QBrush(Qt::transparent, Qt::SolidPattern));
	}
	else if (player.getPlayerType() == player1)
	{
		QBrush brush;
		brush.setTextureImage(QImage("res//MX-thumbnail-256.png").scaled(rayon, rayon));
		setBrush(brush);

	}
	else if (player.getPlayerType() == player2)
	{
		QBrush brush;
		brush.setTextureImage(QImage("res//US-thumbnail-256.png").scaled(rayon,rayon));
		setBrush(brush);
		
	}
}

Player Jetons::getPlayer()
{
	return player;
}

void Jetons::moveRight(int distance)
{
	setPos(x() + distance, y());
}

void Jetons::moveLeft(int distance)
{
	setPos(x() - distance, y());
}

void Jetons::setPlayer(Player p)
{
	player = p;
	if (player.getPlayerType() == playerN)
	{
		setBrush(QBrush(Qt::transparent, Qt::SolidPattern));
	}
	else if (player.getPlayerType() == player1)
	{
		QImage image("res//MX-thumbnail-256.png");
		setBrush(QBrush(image.scaled(rayon, rayon, Qt::KeepAspectRatio)));
	}
	else if (player.getPlayerType() == player2)
	{
		QImage image("res//US-thumbnail-256.png");
		setBrush(QBrush(image.scaled(rayon, rayon, Qt::KeepAspectRatio)));
	}
}


