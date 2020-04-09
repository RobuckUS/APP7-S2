#include "parametreJeu.h"

ParametreJeu::ParametreJeu()
{
	setButton();
	setHlayout();
	setVLayout();
	setWindow();
}

void ParametreJeu::setButton()
{
	jeuretourbtn = new QPushButton("Retour");
	unJoueur = new QPushButton("1 vs PC");
	deuxJoueurs = new QPushButton("1 vs 1");
}

void ParametreJeu::setHlayout()
{
	hlayout = new QHBoxLayout();
	hlayoutdim = new QHBoxLayout();
	hlayoutval = new QHBoxLayout();
	labelH = new QLabel("Hauteur:");
	labelL = new QLabel("Largeur:");
	largeur = new QSpinBox();
	largeur->setRange(6,MaxSize);
	hauteur = new QSpinBox();
	hauteur->setRange(6,MaxSize);
	hlayout->addWidget(unJoueur);
	hlayout->addWidget(deuxJoueurs);
	hlayoutdim->addWidget(labelL);
	hlayoutdim->addWidget(labelH);
	hlayoutval->addWidget(largeur);
	hlayoutval->addWidget(hauteur);
	
}

void ParametreJeu::setVLayout()
{
	vlayout = new QVBoxLayout();
	vlayout->addLayout(hlayoutdim);
	vlayout->addLayout(hlayoutval);
	vlayout->addLayout(hlayout);
	vlayout->addWidget(jeuretourbtn);
}

void ParametreJeu::setWindow()
{
	this->setLayout(vlayout);
}

void ParametreJeu::setValues()
{
	this->diml = largeur->value();
	this->dimh = hauteur->value();
}
