#include "TableauJeu.h"

TableauJeu::TableauJeu()
{

}
TableauJeu::TableauJeu(int l, int h,int wl, int wh)
{
	diml = l;
	dimh = h;
	winl = wl;
	winh = wh; 
	setupWindow();
	setupBoard(diml,dimh,winl,winh);
}

TableauJeu::~TableauJeu()
{
	for (int i = 0; i < diml; i++) {
		for (int j = 0; j < dimh; j++) {
			delete[] grid[i][j];
		}
		delete[] grid[i];
	}
	delete[] grid;
}

void TableauJeu::setupBoard(int l, int h,int winl, int winh)
{
	//creations des cercles de la bonne grosseur
	int sizeCercle = (winh / h+1)-20;
	grid = new QGraphicsEllipseItem **[l];
	for (int i = 0; i < l; i++) {
		grid[i] = new QGraphicsEllipseItem *[h];
		for (int j = 0; j < h; j++) {
			grid[i][j] = new QGraphicsEllipseItem((sizeCercle+sizeCercle*0.1)*i,(sizeCercle+sizeCercle * 0.1)*j,sizeCercle,sizeCercle);
			grid[i][j]->setBrush(QBrush(Qt::black));
			scene->addItem(grid[i][j]);
		}
	}	
}

void TableauJeu::setupWindow()
{
	hlayout = new QHBoxLayout();
	scene = new QGraphicsScene();
	view = new QGraphicsView(this);
	hlayout->addWidget(view);
	this->setLayout(hlayout);
	view->setScene(scene);

}

