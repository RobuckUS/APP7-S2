#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QHBoxLayout>
#include <QGraphicsItemAnimation>

#include "jetons.h"

class TableauJeu : public QGraphicsScene
{
	Q_OBJECT
public:
	TableauJeu();
	TableauJeu(int l, int h, int wWindow, int hWindow);
	void keyPressEvent(QKeyEvent *ev);
	Player winner();
	Player pn;
	QGraphicsItemAnimation *animation;
	void animationMexicain();

	

signals:
	void winnerSignal(Player p);

private:
	Jetons ***tableau;
	QGraphicsPixmapItem ***fond;
	Jetons *enJeu;
	QImage *imageFond;
	QGraphicsScene * scene;
	QGraphicsView * view;
	QHBoxLayout * hlayout;
	

	int length;
	int height;
	int rayon;
	double lengthWindow;
	

	Player p1;
	Player p2;
	

	void setupBoard();
	void enterEvent();
};