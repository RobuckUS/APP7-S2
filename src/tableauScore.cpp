#include "tableauScore.h"

#include <iostream>
#include <QFile>
#include <QString>
#include <QTextStream>

TableauScore::TableauScore()
{
	viewList = new QListWidget(this);
	setButtons();
	showScore();

	setVLayout();
}
void TableauScore::setButtons()
{
	retourBtn = new QPushButton();
	retourBtn->setIconSize(QSize(200, 50));
	retourBtn->setMinimumSize(QSize(100, 60));
	retourBtn->setMaximumSize(QSize(220, 100));
	retourBtn->setIcon(QIcon("res//fleche_retour_icone.png"));
}
void TableauScore::showScore()
{
	
	listFileLine.clear();

	QFile file("res//Score.txt");
	QTextStream instream(&file);

	//Lire dans le fichier et remplir une liste pour chaque line du fichier
	if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
		return;
	while (!instream.atEnd())
	{
		listFileLine << instream.readLine();
	}
	file.close();
	//Affichage de la liste
	for (int i = 0; i < listFileLine.length(); i++)
	{
		splitFileLine = listFileLine[i].split(" ");
		/*QLabel* name = new QLabel(splitFileLine[0]);
		QLabel* win = new QLabel(splitFileLine[1]);
		QLabel* loss = new QLabel(splitFileLine[2]);
		hlayoutList->addWidget(name);
		hlayoutList->addWidget(win);
		hlayoutList->addWidget(loss);*/
		//viewList->addItems(listFileLine);
	}
	//zoneScroll = new QScrollArea;
	//viewList->addItems(listFileLine);
	//zoneScroll->setWidget(viewList)
	viewList->addItems(listFileLine);
}
void TableauScore::setVLayout()
{
	vlayout = new QVBoxLayout();
	vlayout->setSpacing(100);
	vlayout->setAlignment(Qt::AlignCenter);
	vlayout->setMargin(300);

	hlayoutList = new QHBoxLayout();

	//Read file
	//sowScore();
	//viewList->addItems(listFileLine);
	vlayout->addWidget(viewList);
	//vlayout->addWidget(zoneScroll);

	vlayout->addWidget(retourBtn);

	//vlayout->addWidget(vlayout);
	setWindow();
}
void TableauScore::setWindow()
{
	this->setLayout(vlayout);
}