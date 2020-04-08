#include "accueil.h"
Accueil::Accueil()
{
	setTitre();
	setButtons();
	setVLayout();
	setWindow();
}
void Accueil::setTitre()
{
	titre = new QLabel("Connect Four");
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
	vlayout->addWidget(titre, Qt::AlignVCenter, Qt::AlignAbsolute);
	vlayout->addWidget(jouerBtn);
	vlayout->addWidget(tableauScoreBtn);
	vlayout->addWidget(parametreBtn);
	vlayout->addWidget(quitterBtn);

}

void Accueil::setWindow()
{
	this->setLayout(vlayout);
}

