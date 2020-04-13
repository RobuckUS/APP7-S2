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
	QFont font = QFont("Showcard Gothic");
	font.setPointSize(20);

	labelH = new QLabel("Hauteur:");
	labelH->setFont(font);

	labelL = new QLabel("Largeur:");
	labelL->setFont(font);
	
	
	largeur = new QSpinBox();
	largeur->setRange(6,MaxSize);
	hauteur = new QSpinBox();
	hauteur->setRange(6,MaxSize);
	

	hlayoutval = new QHBoxLayout();
	hlayoutval ->addWidget(labelL);
	hlayoutval->addWidget(largeur);
	hlayoutval->addWidget(labelH);
	hlayoutval->addWidget(hauteur);

	hlayout = new QHBoxLayout();
	hlayout->addWidget(jeuretourbtn);
	hlayout->addWidget(deuxJoueurs);
	
}

void ParametreJeu::setVLayout()
{
	vlayout = new QVBoxLayout();
	vlayout->addWidget(new QLabel(""));
	vlayout->setAlignment(Qt::AlignCenter);
	vlayout->setSpacing(50);

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
