#include "parametre.h"
Parametre::Parametre()
{
	setButtons();
	setVLayout();
	setWindow();
}

void Parametre::setButtons()
{
	musiqueBtn = new QPushButton("Musique On");
	pleinEcranBtn = new QPushButton("Plein Ecran");
	volumeEffetSlider = new QSlider(Qt::Horizontal);
	volumeMusiqueSlider = new QSlider(Qt::Horizontal);
	retourBtn = new QPushButton("Retour");

}

void Parametre::setMusiqueBtn()
{
	if (musiqueBtn->text() == "Musique On")
		musiqueBtn->setText("Musique Off");
	else
		musiqueBtn->setText("Musique On");
}
void Parametre::setPleinEcranBtn()
{
	if (pleinEcranBtn->text() == "Plein Ecran")
		pleinEcranBtn->setText("Ecran fenetree");
	else
		pleinEcranBtn->setText("Plein Ecran");
}

void Parametre::setVLayout()
{
	vlayout = new QVBoxLayout();
	vlayout->addWidget(musiqueBtn);
	vlayout->addWidget(pleinEcranBtn);
	vlayout->addWidget(volumeEffetSlider);
	vlayout->addWidget(volumeMusiqueSlider);
	vlayout->addWidget(retourBtn);
}

void Parametre::setWindow()
{
	this->setLayout(vlayout);
}