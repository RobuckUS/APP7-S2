#include "accueil.h"

Accueil::Accueil()
{
	setButtons();
	setVLayout();
	setWindow();
}

void Accueil::setButtons()
{
	jouerBtn = new QPushButton();
	jouerBtn->setIcon(QIcon("res//img//button//play_icon.png"));
	jouerBtn->setMinimumSize(QSize(120, 72));
	jouerBtn->setIconSize(QSize(200, 50));

	tableauScoreBtn = new QPushButton();
	tableauScoreBtn->setIcon(QIcon("res//img//button//icone_tableau_des_scores.png"));
	tableauScoreBtn->setIconSize(QSize(200, 50));
	tableauScoreBtn->setMinimumSize(QSize(120, 72));

	parametreBtn = new QPushButton();
	parametreBtn->setIcon(QIcon("res//img//button//icone_parametre.png"));
	parametreBtn->setIconSize(QSize(200, 50));
	parametreBtn->setMinimumSize(QSize(120, 72));

	quitterBtn = new QPushButton();
	quitterBtn->setIcon(QIcon("res//img//button//quit_icon.png"));
	quitterBtn->setIconSize(QSize(200, 50));
	quitterBtn->setMinimumSize(QSize(120, 72));
}

void Accueil::setVLayout()
{
	vlayout = new QVBoxLayout();
	vlayout->setAlignment(Qt::AlignCenter);

	vlayout->addWidget(jouerBtn, Qt::AlignCenter);
	vlayout->addWidget(tableauScoreBtn, Qt::AlignCenter);
	vlayout->addWidget(parametreBtn, Qt::AlignCenter);
	vlayout->addWidget(quitterBtn, Qt::AlignCenter);
}

void Accueil::setWindow()
{
	this->setLayout(vlayout);
	
}
