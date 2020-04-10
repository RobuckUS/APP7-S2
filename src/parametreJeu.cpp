#include "parametreJeu.h"
#include <QLabel>

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
	hlayoutval ->addWidget(labelL);
	hlayoutval->addWidget(largeur);
	hlayoutval->addWidget(labelH);
	hlayoutval->addWidget(hauteur);
	
}

void ParametreJeu::setVLayout()
{
	vlayout = new QVBoxLayout();
	vlayout->addWidget(new QLabel(""));
	vlayout->addLayout(hlayoutdim);
	vlayout->addLayout(hlayoutval);
	vlayout->addLayout(hlayout);
	vlayout->addWidget(jeuretourbtn);
	vlayout->setMargin(400);
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
