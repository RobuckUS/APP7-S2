#include "tableauScore.h"

#include <iostream>
#include <QFile>
#include <QString>
#include <QTextStream>

TableauScore::TableauScore()
{
	QFont font = QFont("Showcard Gothic");
	font.setPointSize(20);

	viewList = new QListWidget(this);
	viewList->setFont(font);
	viewList->setMinimumSize(300, 100);
	viewList->setMaximumSize(500, 125);
	viewList->setStyleSheet("QListView{ \
								background-color: rgba(255,255,255, 0); \
								border-top: 0px solid rgb(40,40,40); min - width:133px; \
								margin:0px; \
		}");

	setButtons();
	showScore();

	setVLayout();
}
void TableauScore::setButtons()
{
	retourBtn = new QPushButton();
	retourBtn->setIconSize(QSize(200, 50));
	retourBtn->setMinimumSize(QSize(120, 72));
	retourBtn->setIcon(QIcon("res//img//button//fleche_retour_icone.png"));
}
void TableauScore::showScore()
{
	viewList->clear();
	listFileLine.clear();

	QFile file("res//score.txt");
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
		QString line;
		splitFileLine = listFileLine[i].split(" ");
		if (splitFileLine[0].length() < 5)
		{
			line = QString(splitFileLine[0] + "\t\t\t" + splitFileLine[1] + "\t\t" + splitFileLine[2]);
		}
		else
		{
			line = QString(splitFileLine[0] + "\t\t" + splitFileLine[1] + "\t\t" + splitFileLine[2]);
		}
		/*QLabel* name = new QLabel(splitFileLine[0]);
		QLabel* win = new QLabel(splitFileLine[1]);
		QLabel* loss = new QLabel(splitFileLine[2]);*/
		
		viewList->addItem(line);
	}
	/*viewList->addItems(listFileLine);*/
}
void TableauScore::setVLayout()
{
	QFont font = QFont("Showcard Gothic");
	font.setPointSize(20);
	QLabel *lbl = new QLabel("Nom\tGagne\tPerdu");
	lbl->setFont(font);

	vlayout = new QVBoxLayout();
	vlayout->setMargin(200);

	vlayout->setAlignment(Qt::AlignCenter);
	vlayout->addWidget(lbl, Qt::AlignCenter);
	vlayout->addWidget(viewList, Qt::AlignCenter);
	vlayout->addSpacing(75);
	vlayout->addWidget(retourBtn, Qt::AlignCenter);
	setWindow();
}
void TableauScore::setWindow()
{
	
	

	this->setLayout(vlayout);
	
}