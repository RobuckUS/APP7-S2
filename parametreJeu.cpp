#include "parametreJeu.h"

ParametreJeu::ParametreJeu()
{
	setButton();
	setCheckbox();
	setVLayout();
	setWindow();
}

void ParametreJeu::setButton()
{
	jouer = new QPushButton("Jouer");
	retour = new QPushButton("Retour");
}

void ParametreJeu::setCheckbox()
{
	nbJoueur = new QCheckBox();
	dimension = new QCheckBox();
}

void ParametreJeu::setVLayout()
{
	vlayout = new QVBoxLayout();
	vlayout->addWidget(nbJoueur);
	vlayout->addWidget(dimension);
	vlayout->addWidget(jouer);
	vlayout->addWidget(retour);
}

void ParametreJeu::setWindow()
{
	this->setLayout(vlayout);
}
