#include "jetons.h"

Jetons::Jetons()
{
}

Jetons::Jetons(int x, int y, int r, Player p) : QGraphicsEllipseItem(x, y, r, r)
{
	rayon = r;
	player = p;
	xPos = x;
	yPos = y;
	if (player.getPlayerType() == playerN)
	{
		setBrush(QBrush(Qt::transparent, Qt::SolidPattern));
	}
	else if (player.getPlayerType() == player1)
	{
		QBrush brush;
		brush.setTextureImage(QImage("res//img//token//MX-256.png").scaled(rayon, rayon));

		QTransform transform;
		transform.translate(x, y);
		brush.setTransform(transform);
		setBrush(brush);

	}
	else if (player.getPlayerType() == player2)
	{
		QBrush brush;
		brush.setTextureImage(QImage("res//img//token//US-256.png").scaled(rayon, rayon));
		
		QTransform transform;
		transform.translate(x, y);
		brush.setTransform(transform);
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
		QBrush brush;
		brush.setTextureImage(QImage("res//img//token//MX-256.png").scaled(rayon, rayon));

		QTransform transform;
		transform.translate(xPos, yPos);
		brush.setTransform(transform);

		setBrush(brush);
	}
	else if (player.getPlayerType() == player2)
	{
		QBrush brush;
		brush.setTextureImage(QImage("res//img//token//US-256.png").scaled(rayon, rayon));

		QTransform transform;
		transform.translate(xPos, yPos);
		brush.setTransform(transform);

		setBrush(brush);
	}
}


