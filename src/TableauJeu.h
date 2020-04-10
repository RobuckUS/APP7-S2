#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QHBoxLayout>
#include "jetons.h"

class TableauJeu : public QGraphicsScene
{
public:
	TableauJeu();
	TableauJeu(int l, int h, int wWindow, int hWindow);
	void keyPressEvent(QKeyEvent *ev);
	Player winner();

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
	int lengthWindow;
	

	Player p1;
	Player p2;
	Player pn;

	void setupBoard();
	void enterEvent();
	void setupWindow();
};