#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QHBoxLayout>
#include <QGraphicsEllipseItem>

class TableauJeu : public QWidget
{
public:
	TableauJeu();
	TableauJeu(int l,int h, int winl, int winh);
	~TableauJeu();
	QGraphicsScene * scene;
	QGraphicsView * view;
	QHBoxLayout * hlayout;
private:
	void setupBoard(int l, int h, int winl, int winh);
	void setupWindow();
	int diml;
	int dimh;
	int winl;
	int winh;
	QGraphicsEllipseItem *** grid;
	QGraphicsEllipseItem * cercle;
};
 