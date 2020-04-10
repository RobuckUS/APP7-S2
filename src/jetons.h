#include <QGraphicsEllipseItem>
#include <QBrush>
#include <iostream>
#include "player.h"
using namespace std;
class Jetons : public QObject, public QGraphicsEllipseItem
{
	Q_OBJECT
	Q_PROPERTY(QPointF pos READ pos WRITE setPos)
public:
	Jetons();
	Jetons(int x, int y, int rayon, Player p);
	Player getPlayer();
	void moveRight(int distance);
	void moveLeft(int distance);
	void setPlayer(Player p);
	


private:
	QPixmap icon;
	Player player;
	int rayon;
	int xPos;
	int yPos;
};