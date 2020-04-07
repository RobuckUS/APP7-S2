#include "mainWindow.h"
MainWindow::MainWindow()
{
	accueil = new Accueil();
	parametre = new Parametre();
	parametreJeu = new ParametreJeu();
	setActions();
	this->setCentralWidget(accueil);
}
void MainWindow::setActions()
{
	connect(accueil->parametreBtn, SIGNAL(released()), this, SLOT(setParametre()));
	connect(accueil->jouerBtn, SIGNAL(released()), this, SLOT(setParametreJeu()));
	connect(parametre->retourBtn, SIGNAL(released()), this, SLOT(retourMenu()));
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