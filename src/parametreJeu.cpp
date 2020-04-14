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
	deuxJoueurs = new QPushButton();
	deuxJoueurs->setIcon(QIcon("res//play_icon.png"));
	deuxJoueurs->setIconSize(QSize(200, 50));
	deuxJoueurs->setMinimumSize(QSize(100, 60));
	deuxJoueurs->setMaximumSize(QSize(325, 100));


	jeuretourbtn = new QPushButton();
	jeuretourbtn->setIcon(QIcon("res//fleche_retour_icone.png"));
	jeuretourbtn->setIconSize(QSize(200, 50));
	jeuretourbtn->setMinimumSize(QSize(100, 60));
	jeuretourbtn->setMaximumSize(QSize(325, 100));
	

}

void ParametreJeu::setHlayout()
{
	/*Configuration du font*/
	
	QFont font = QFont("Showcard Gothic");
	font.setPointSize(20);

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
	txtNom1->setFixedSize(250, 40);
	txtNom1->setMaximumWidth(250);
	txtNom1->setFont(font);
	txtNom1->setMaxLength(6);
	txtNom1->setText("P1");

	txtNom2 = new QLineEdit();
	txtNom2->setFixedSize(250, 40);
	txtNom2->setMaximumWidth(250);
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
	hname->addWidget(lblNameP1);
	hname->addWidget(txtNom1);
	hname->addSpacing(30);
	hname->addWidget(lblNameP2);
	hname->addWidget(txtNom2);


	/*Hlayout pour les valeurs*/
	hlayoutval = new QHBoxLayout();
	hlayoutval ->addWidget(labelL);
	hlayoutval->addWidget(largeur);
	hlayoutval->addWidget(labelH);
	hlayoutval->addWidget(hauteur);

	/*HLayout pour les boutons*/
	hlayout = new QHBoxLayout();
	hlayout->addWidget(jeuretourbtn);
	hlayout->addWidget(deuxJoueurs);
	
}

void ParametreJeu::setVLayout()
{
	vlayout = new QVBoxLayout();
	vlayout->addWidget(new QLabel(""));
	vlayout->setAlignment(Qt::AlignCenter);
	vlayout->setSpacing(20);


	/*Ajout des layout au hlayout*/
	vlayout->addLayout(hname);
	vlayout->addLayout(hlayoutval);
	vlayout->addLayout(hlayout);
	vlayout->addWidget(jeuretourbtn);
	
}

void ParametreJeu::setWindow()
{
	
	vlayout->setContentsMargins(QMargins(430, 250, 440, 200));
	setLayout(vlayout);
	
}

void ParametreJeu::setValues()
{
	this->diml = largeur->value();
	this->dimh = hauteur->value();
}
