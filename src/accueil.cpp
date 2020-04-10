#include "accueil.h"
Accueil::Accueil()
{
	setButtons();
	setVLayout();
	setWindow();
}

void Accueil::setButtons()
{
	jouerBtn = new QPushButton("Jouer");
	tableauScoreBtn = new QPushButton("Tableau des Scores");
	parametreBtn = new QPushButton("Parametre");
	quitterBtn = new QPushButton("Quitter");
}

void Accueil::setVLayout()
{
	vlayout = new QVBoxLayout();
	vlayout->addWidget(new QLabel(""));
	vlayout->addWidget(jouerBtn);
	vlayout->addWidget(tableauScoreBtn);
	vlayout->addWidget(parametreBtn);
	vlayout->addWidget(quitterBtn);
	vlayout->setMargin(400);
	
}

void Accueil::setWindow()
{
	this->setLayout(vlayout);
	
}

