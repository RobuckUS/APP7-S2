#include "tableauJeu.h"
#include <QKeyEvent>
#include <QPropertyAnimation>
#include <QTimeLine>

TableauJeu::TableauJeu()
{
	

	length = 7;
	height = 6;
	rayon = 100;

	p1 = Player("Player 1", player1);
	p2 = Player("Player 2", player2);
	pn = Player("null", playerN);

	enJeu = new Jetons(0, 0, rayon, p2);
	addItem(enJeu);


	setupBoard();
	setFocus();

	isPlaying = true;
}

TableauJeu::TableauJeu(int l, int h, int wWindow, int hWindow)
{
	length = l;
	height = h;
	lengthWindow = wWindow;
	rayon = (hWindow*0.9) / (height + 1);

	p1 = Player("Player 1", player1);
	p2 = Player("Player 2", player2);
	pn = Player("null", playerN);
	enJeu = new Jetons(lengthWindow / 2 - (rayon*length) / 2, 0, rayon, p2);
	addItem(enJeu);
	setupBoard();
}

TableauJeu::TableauJeu(int l, int h, int wWindow, int hWindow, Player p1, Player p2)
{
	length = l;
	height = h;
	lengthWindow = wWindow;
	rayon = (hWindow*0.9) / (height + 1);

	this->p1 = p1;
	this->p2 = p2;
	pn = Player("null", playerN);
	
	enJeu = new Jetons(lengthWindow / 2 - (rayon*length) / 2, 0, rayon, this->p2);
	addItem(enJeu);
	setupBoard();
}

void TableauJeu::keyPressEvent(QKeyEvent * ev)
{
	if (isPlaying)
	{
		if (ev->key() == Qt::Key_Left)
		{
			if (enJeu->x() > 0)
			{
				enJeu->moveLeft(rayon);
			}
		}
		else if (ev->key() == Qt::Key_Right)
		{
			if (enJeu->x() < (length - 1) * rayon)
			{
				enJeu->moveRight(rayon);
			}
		}
		else if (ev->key() == Qt::Key_Space)
		{
			enterEvent();
			if (!(winner() == pn))
			{
				isPlaying = false;
				Player pLost;
				if (winner() == p1)
				{
					pLost = p2;
				}
				else
				{
					pLost = p1;
				}
				emit(winnerSignal(winner(), pLost));
			}
		}
	}	//End of isPlaying
}


void TableauJeu::setupBoard()
{
	imageFond = new QImage("res//img//token//empty-cache-256.png");
  	tableau = new Jetons **[length];
	fond = new QGraphicsPixmapItem**[length];
	for (int i = 0; i < length; i++)
	{
		tableau[i] = new Jetons*[height];
		fond[i] = new QGraphicsPixmapItem*[height];
		for (int j = 0; j < height; j++)
		{
			fond[i][j] = new QGraphicsPixmapItem(QPixmap::fromImage( imageFond->scaled(rayon, rayon, Qt::KeepAspectRatio)));
			tableau[i][j] = new Jetons(lengthWindow / 2 - (rayon*length) / 2 + rayon*i, rayon*j + rayon, rayon, pn);
			addItem(tableau[i][j]);
			fond[i][j]->setOffset(lengthWindow / 2 - (rayon*length)/2 + rayon*i, rayon*j+rayon);
			addItem(fond[i][j]);
		}
	}

	
}


void TableauJeu::enterEvent()
{
	int xIndex = enJeu->x() / rayon;
	int count = height - 1;
	while (tableau[xIndex][count]->getPlayer().getPlayerType() != playerN && count > 0)
	{
		count--;
	}
	if (count >= 0 && tableau[xIndex][count]->getPlayer().getPlayerType() == playerN)
	{
		tableau[xIndex][count]->setPlayer(enJeu->getPlayer());
		if (enJeu->getPlayer().getPlayerType() == player1)
		{
			enJeu->setPlayer(p2);
		}
		else
		{
			enJeu->setPlayer(p1);
		}
		
	}
}


/*
Code pour regarder qui est le gagnant. La methode retourne le nom du gagnant, ou le joueur null.
*/
Player TableauJeu ::winner()
{
	//V�rification de l'horizontale
	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < height - 3; j++)
		{
			if (tableau[i][j]->getPlayer() == p1 && tableau[i][j + 1]->getPlayer() == p1 && tableau[i][j + 2]->getPlayer() == p1 && tableau[i][j + 3]->getPlayer() == p1)
			{
				return p1;
			}
			else if (tableau[i][j]->getPlayer() == p2 && tableau[i][j + 1]->getPlayer() == p2 && tableau[i][j + 2]->getPlayer() == p2 && tableau[i][j + 3]->getPlayer() == p2)
			{
				return p2;
			}
		}
	}

	//V�rification du verticale
	for (int i = length - 1; i >= 3; i--)
	{
		for (int j = 0; j < height; j++)
		{
			if (tableau[i][j]->getPlayer() == p1 && tableau[i - 1][j]->getPlayer() == p1 && tableau[i - 2][j]->getPlayer() == p1 && tableau[i - 3][j]->getPlayer() == p1)
			{
				return p1;
			}
			if (tableau[i][j]->getPlayer() == p2 && tableau[i - 1][j]->getPlayer() == p2 && tableau[i - 2][j]->getPlayer() == p2 && tableau[i - 3][j]->getPlayer() == p2)
			{
				return p2;
			}
		}
	}

	//V�rification diagonale Haut gauche a en bas droite
	for (int i = 0; i < length - 3; i++)
	{
		for (int j = 0; j < height - 3; j++)
		{
			if (tableau[i][j]->getPlayer() == p1 && tableau[i + 1][j + 1]->getPlayer() == p1 && tableau[i + 2][j + 2]->getPlayer() == p1&& tableau[i + 3][j + 3]->getPlayer() == p1)
			{
				return p1;
			}
			if (tableau[i][j]->getPlayer() == p2 && tableau[i + 1][j + 1]->getPlayer() == p2 && tableau[i + 2][j + 2]->getPlayer() == p2 && tableau[i + 3][j + 3]->getPlayer() == p2)
			{
				return p2;
			}
		}
	}

	//Verification diagonale haut droite a bas gauche
	for (int i = 0; i < length - 3; i++)
	{
		for (int j = height - 1; j >= 3; j--)
		{
			if (tableau[i][j]->getPlayer() == p1 && tableau[i + 1][j - 1]->getPlayer() == p1 && tableau[i + 2][j - 2]->getPlayer() == p1&& tableau[i + 3][j - 3]->getPlayer() == p1)
			{
				return p1;
			}
			if (tableau[i][j]->getPlayer() == p2 && tableau[i + 1][j - 1]->getPlayer() == p2 && tableau[i + 2][j - 2]->getPlayer() == p2 && tableau[i + 3][j - 3]->getPlayer() == p2)
			{
				return p2;
			}
		}
	}

	return pn;
}



void TableauJeu::animationMexicain()
{
	animation = new QGraphicsItemAnimation;
	
	QGraphicsPixmapItem *mexican = new QGraphicsPixmapItem(QPixmap("res//img//background//FG-MX-anim.png"));
	timer = new QTimeLine(4000);
	timer->setFrameRange(0, 100);

	
	animation->setItem(mexican);
	animation->setTimeLine(timer);

	for (int i = lengthWindow-300; i >0; i--)
	{
		animation->setPosAt(i / lengthWindow, QPointF(lengthWindow-i-300, 0));
	}

	timer->start();
	addItem(mexican);
	

}

void TableauJeu::animationTrump()
{
	animation = new QGraphicsItemAnimation;
	QGraphicsPixmapItem *trump = new QGraphicsPixmapItem(QPixmap("res//img//background//FG-US-anim.png"));

	timer = new QTimeLine(4000);
	animation->setItem(trump);
	animation->setTimeLine(timer);
	
	for (double i = 0.0; i < 1.2; i=i + 0.05)
	{
		animation->setScaleAt(i / 100, i, i);
	}
	timer->start();
	addItem(trump);
}
