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
	jouerBtn->setIcon(QIcon("res//play_icon.png"));
	jouerBtn->setIconSize(QSize(200, 50));
	jouerBtn->setMinimumSize(QSize(100, 60));

	tableauScoreBtn = new QPushButton();
	tableauScoreBtn->setIcon(QIcon("res//icone_tableau_des_scores.png"));
	tableauScoreBtn->setIconSize(QSize(300, 225));
	tableauScoreBtn->setMinimumSize(QSize(100, 60));
	tableauScoreBtn->setMaximumSize(QSize(325, 225));

	parametreBtn = new QPushButton();
	parametreBtn->setIcon(QIcon("res//icone_parametre.png"));
	parametreBtn->setIconSize(QSize(200, 50));
	parametreBtn->setMinimumSize(QSize(100, 60));

	quitterBtn = new QPushButton();
	quitterBtn->setIcon(QIcon("res//quit_icon.png"));
	quitterBtn->setIconSize(QSize(200, 50));
	quitterBtn->setMinimumSize(QSize(100, 60));
}

void Accueil::setVLayout()
{
	vlayout = new QVBoxLayout();
	vlayout->setSpacing(100);
	vlayout->setAlignment(Qt::AlignCenter);

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
