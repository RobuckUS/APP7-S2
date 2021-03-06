#include "parametre.h"
#include <QLabel>
Parametre::Parametre()
{
	musique = true;
	setButtons();
	setVLayout();
	setWindow();
}

void Parametre::setButtons()
{
	musiqueBtn = new QPushButton();
	connect(musiqueBtn, SIGNAL(released()), this, SLOT(setMusiqueBtn()));
	musiqueBtn->setIcon(QIcon("res//img//button//icone_musique_on.png"));
	musiqueBtn->setIconSize(QSize(200, 75));
	musiqueBtn->setMinimumSize(QSize(100, 60));
	musiqueBtn->setMaximumWidth(300);






	/*Configuration du slider de volume pour le bouton de musique*/
	volumeMusiqueSlider = new QSlider(Qt::Horizontal);
	volumeMusiqueSlider->setMinimumSize(QSize(100, 25));
	volumeMusiqueSlider->setMaximumWidth(300);
	volumeMusiqueSlider->setValue(100);
	connect(volumeMusiqueSlider, SIGNAL(valueChanged(int)), this, SLOT(musiqueBtnAdjust(int))); //	/*Adjuster le bouton de musique en fonction du volume choisi*/



	retourBtn = new QPushButton();
	retourBtn->setIconSize(QSize(200, 50));
	retourBtn->setMinimumSize(QSize(100, 60));
	retourBtn->setMaximumWidth(300);
	retourBtn->setIcon(QIcon("res//img//button//fleche_retour_icone.png"));
}

void Parametre::setMusiqueBtn()
{
	if (musique)
	{
		musiqueBtn->setIcon(QIcon("res//img//button//icone_musique_off.png"));
		volumeMusiqueSlider->setValue(0);
		musique = false;
	}
	else
	{
		musiqueBtn->setIcon(QIcon("res//img//button//icone_musique_on.png"));
		volumeMusiqueSlider->setValue(100);
		musique = true;
	}
}




void Parametre::musiqueBtnAdjust(int volume)
{
	if (volume == 0)
	{
		musiqueBtn->setIcon(QIcon("res//img//button//icone_musique_off.png"));
	}
	else
	{
		musiqueBtn->setIcon(QIcon("res//img//button//icone_musique_on.png"));
	}
}

void Parametre::setVLayout()
{
	vlayout = new QVBoxLayout();
	vlayout->setAlignment(Qt::AlignCenter);
	
	vlayout->addWidget(musiqueBtn, Qt::AlignCenter);
	vlayout->addWidget(volumeMusiqueSlider, Qt::AlignCenter);
	vlayout->addSpacing(100);
	vlayout->addWidget(retourBtn, Qt::AlignCenter);
}

void Parametre::setWindow()
{
	this->setLayout(vlayout);
}