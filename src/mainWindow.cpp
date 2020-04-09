#include "mainWindow.h"
MainWindow::MainWindow()
{
	//Dimensions de l'ecran
	QSize availableSize = qApp->desktop()->availableGeometry().size();
	winl = availableSize.width();
	winh = availableSize.height();
	winl *= 0.9; // 90% of the screen size
	winh*= 0.9; // 90% of the screen size
	int x = (availableSize.width() - winl) / 2;
	int y = (availableSize.height() - winh) / 2 - 50;
	move(x, y);
	this->setFixedSize(winl, winh);

	accueil = new Accueil();
	parametre = new Parametre();
	parametreJeu = new ParametreJeu();
	setActions();
	this->setCentralWidget(accueil);
}
MainWindow::~MainWindow()
{

}

void MainWindow::setActions()
{
	connect(accueil->parametreBtn, SIGNAL(released()), this, SLOT(setParametre()));
	connect(accueil->jouerBtn, SIGNAL(released()), this, SLOT(setParametreJeu()));
	connect(parametre->retourBtn, SIGNAL(released()), this, SLOT(retourMenu()));
	connect(parametreJeu->jeuretourbtn, SIGNAL(released()), this,SLOT(retourMenu()));
	connect(parametreJeu->unJoueur, SIGNAL(clicked()), this, SLOT(setTableauJeu1()));
	connect(parametreJeu->deuxJoueurs, SIGNAL(clicked()), this, SLOT(setTableauJeu2()));

}
void MainWindow::setParametreJeu()
{
	QWidget* savedWidget = this->centralWidget();
	savedWidget->setParent(0);
	this->setCentralWidget(parametreJeu);
}
void MainWindow::setParametre()
{
	QWidget* savedWidget = this->centralWidget();
	savedWidget->setParent(0);
	this->setCentralWidget(parametre);
}
void MainWindow::retourMenu()
{
	QWidget* savedWidget = this->centralWidget();
	savedWidget->setParent(0);
	this->setCentralWidget(accueil);
}
void MainWindow::setTableauJeu1()
{
	parametreJeu->setValues();
	this->diml = parametreJeu->diml;
	this->dimh = parametreJeu->dimh;
	tableauJeu = new TableauJeu(diml,dimh,winl,winh);
	QWidget* savedWidget = this->centralWidget();
	savedWidget->setParent(0);
	this->setCentralWidget(tableauJeu);
}

void MainWindow::setTableauJeu2()
{
	parametreJeu->setValues();
	this->diml = parametreJeu->diml;
	this->dimh = parametreJeu->dimh;
	tableauJeu = new TableauJeu();
	QWidget* savedWidget = this->centralWidget();
	savedWidget->setParent(0);
	this->setCentralWidget(tableauJeu);
}
