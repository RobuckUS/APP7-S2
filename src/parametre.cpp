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
	musiqueBtn->setIcon(QIcon("res//icone_musique_on.png"));
	musiqueBtn->setIconSize(QSize(200, 100));
	musiqueBtn->setMinimumSize(QSize(100, 60));
	musiqueBtn->setMaximumSize(QSize(220, 100));
	


	pleinEcranBtn = new QPushButton("Plein Ecran");
	pleinEcranBtn->setIconSize(QSize(300, 225));
	pleinEcranBtn->setMinimumSize(QSize(100, 60));
	pleinEcranBtn->setMaximumSize(QSize(325, 225));

	volumeEffetSlider = new QSlider(Qt::Horizontal);
	volumeEffetSlider->setValue(100);
	

	/*Configuration du slider de volume pour le bouton de musique*/
	volumeEffetSlider->setMaximumSize(QSize(300, 50));
	volumeMusiqueSlider = new QSlider(Qt::Horizontal);
	volumeMusiqueSlider->setMaximumSize(QSize(300, 50));
	volumeMusiqueSlider->setValue(100);
	connect(volumeMusiqueSlider, SIGNAL(valueChanged(int)), this, SLOT(musiqueBtnAdjust(int))); //	/*Adjuster le bouton de musique en fonction du volume choisi*/



	retourBtn = new QPushButton("Retour");
	retourBtn->setIconSize(QSize(200, 100));
	retourBtn->setMinimumSize(QSize(100, 60));
	retourBtn->setMaximumSize(QSize(220, 100));
}

void Parametre::setMusiqueBtn()
{
	if (musique)
	{
		musiqueBtn->setIcon(QIcon("res//icone_musique_off.png"));
		volumeMusiqueSlider->setValue(0);
		musique = false;
	}
	else
	{
		musiqueBtn->setIcon(QIcon("res//icone_musique_on.png"));
		volumeMusiqueSlider->setValue(100);
		musique = true;
	}
}


void Parametre::setPleinEcranBtn()
{
	if (pleinEcranBtn->text() == "Plein Ecran")
		pleinEcranBtn->setText("Ecran fenetree");
	else
		pleinEcranBtn->setText("Plein Ecran");
}

void Parametre::musiqueBtnAdjust(int volume)
{
	if (volume == 0)
	{
		musiqueBtn->setIcon(QIcon("res//icone_musique_off.png"));
	}
	else
	{
		musiqueBtn->setIcon(QIcon("res//icone_musique_on.png"));
	}
}

void Parametre::setVLayout()
{
	vlayout = new QVBoxLayout();
	vlayout->setSpacing(100);
	vlayout->setAlignment(Qt::AlignCenter);
	vlayout->setMargin(300);

	vlayout->addWidget(musiqueBtn);
	vlayout->addWidget(volumeMusiqueSlider);
	vlayout->addWidget(volumeEffetSlider);
	
	vlayout->addWidget(retourBtn);
}

void Parametre::setWindow()
{
	this->setLayout(vlayout);
}