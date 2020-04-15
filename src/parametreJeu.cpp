#include "parametreJeu.h"
#include <iostream>
#include <QLabel>
using namespace std;

ParametreJeu::ParametreJeu()
{
	setButton();
	setHlayout();
	setVLayout();
	setWindow();
}

void ParametreJeu::setButton()
{
	deuxJoueurs = new QPushButton();
	deuxJoueurs->setIcon(QIcon("res//img//button//play_icon.png"));
	deuxJoueurs->setIconSize(QSize(200, 50));
	deuxJoueurs->setMinimumSize(QSize(60, 36));
	deuxJoueurs->setMaximumWidth(200);


	jeuretourbtn = new QPushButton();
	jeuretourbtn->setIcon(QIcon("res//img//button//fleche_retour_icone.png"));
	jeuretourbtn->setIconSize(QSize(200, 50));
	jeuretourbtn->setMinimumSize(QSize(60, 36));
	jeuretourbtn->setMaximumWidth(200);
	

}

void ParametreJeu::setHlayout()
{
	/*Configuration du font*/
	
	QFont font = QFont("Showcard Gothic");
	font.setPointSize(20 );

	/*Configurations Labels*/
	labelH = new QLabel("Hauteur:");
	labelH->setFont(font);
	labelL = new QLabel("Largeur:");
	labelL->setFont(font);
	lblNameP1 = new QLabel("Trump:");
	lblNameP1->setFont(font);
	lblNameP2 = new QLabel("Senor:");
	lblNameP2->setFont(font);

	/*QTextEdit pour les noms*/
	txtNom1 = new QLineEdit();
	txtNom1->setMinimumSize(62.5, 40);
	txtNom1->setMaximumWidth(300);
	txtNom1->setFont(font);
	txtNom1->setMaxLength(6);
	txtNom1->setText("P1");

	txtNom2 = new QLineEdit();
	txtNom2->setMinimumSize(62.5, 40);
	txtNom2->setMaximumWidth(300);
	txtNom2->setFont(font);
	txtNom2->setMaxLength(6);
	txtNom2->setText("P2");
	/*Fonction pour les QSpinBox pour la taille du tableau*/
	largeur = new QSpinBox();
	largeur->setRange(6,MaxSize);
	largeur->setFont(font);
	hauteur = new QSpinBox();
	hauteur->setRange(6,MaxSize);
	hauteur->setFont(font);
	
	/*Hlayout pour les noms*/
	hname = new QHBoxLayout();
	hname->setSpacing(0);
	hname->addWidget(lblNameP1, Qt::AlignCenter);
	hname->addWidget(txtNom1, Qt::AlignCenter);
	hname->addSpacing(20);
	hname->addWidget(lblNameP2, Qt::AlignCenter);
	hname->addWidget(txtNom2, Qt::AlignCenter);


	/*Hlayout pour les valeurs*/
	hlayoutval = new QHBoxLayout();
	hlayoutval->setSpacing(0);
	hlayoutval ->addWidget(labelL, Qt::AlignCenter);
	hlayoutval->addWidget(largeur, Qt::AlignCenter);
	hlayoutval->addSpacing(20);
	hlayoutval->addWidget(labelH, Qt::AlignCenter);
	hlayoutval->addWidget(hauteur, Qt::AlignCenter);

	/*HLayout pour les boutons*/
	hlayout = new QHBoxLayout();
	hlayout->addWidget(jeuretourbtn, Qt::AlignCenter);
	hlayout->addWidget(deuxJoueurs, Qt::AlignCenter);
	
}

void ParametreJeu::setVLayout()
{
	vlayout = new QVBoxLayout();
	vlayout->setAlignment(Qt::AlignCenter);
	


	/*Ajout des layout au hlayout*/
	vlayout->addLayout(hname, Qt::AlignHCenter);
	vlayout->addLayout(hlayoutval, Qt::AlignCenter);
	vlayout->addLayout(hlayout, Qt::AlignCenter);
	vlayout->addWidget(jeuretourbtn, Qt::AlignCenter);
	
}

void ParametreJeu::setWindow()
{
	vlayout->setContentsMargins(200, 0, 200, 0);
	setLayout(vlayout);
	
}

void ParametreJeu::setValues()
{
	this->diml = largeur->value();
	this->dimh = hauteur->value();
}
