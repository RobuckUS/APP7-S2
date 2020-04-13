#include "mainWindow.h"
MainWindow::MainWindow()
{
	//Dimensions de l'ecran
	QSize availableSize = qApp->desktop()->availableGeometry().size();
	winl = availableSize.width();
	winh = availableSize.height();
	winl *= 0.9; // 90% of the screen size
	winh*= 0.9; // 90% of the screen size
	int x = (availableSize.width() - winl) / 2;
	int y = (availableSize.height() - winh) / 2 - 50;
	move(x, y);
	this->setFixedSize(winl, winh);
	setBackground("res//BackGroundFinale.png");
	accueil = new Accueil();
	parametre = new Parametre();
	parametreJeu = new ParametreJeu();
	setActions();
	setCentralWidget(accueil);
	setBackgroundMusique();

}
MainWindow::~MainWindow()
{

}

void MainWindow::setActions()
{
	/*Boutons present dans l'accueil*/
	connect(accueil->parametreBtn, SIGNAL(released()), this, SLOT(setParametre()));
	connect(accueil->jouerBtn, SIGNAL(released()), this, SLOT(setParametreJeu()));
	connect(accueil->quitterBtn, SIGNAL(clicked()), this, SLOT(quitter()));

	/*Boutons dans parametre*/
	connect(parametre->retourBtn, SIGNAL(released()), this, SLOT(retourMenu()));
	connect(parametre->musiqueBtn, SIGNAL(released()), this, SLOT(musiqueONandOFF()));

	/*Sliders dans parametre*/
	connect(parametre->volumeMusiqueSlider, SIGNAL(valueChanged(int)), this, SLOT(volumeBackgroundMusic(int)));

	/*Boutons dans parametre jeu*/
	connect(parametreJeu->jeuretourbtn, SIGNAL(released()), this,SLOT(retourMenu()));
	connect(parametreJeu->deuxJoueurs, SIGNAL(clicked()), this, SLOT(setTableauJeu1()));
	
}
void MainWindow::setBackground(QString fileName)
{
	QPixmap bkgnd(fileName);
	bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
	QPalette palette;
	palette.setBrush(QPalette::Background, bkgnd);
	this->setPalette(palette);
}
void MainWindow::setBackgroundMusique()
{
	/*Playlist, suffit de addmedia pour ajouter de nouvelles chansons*/
	QMediaPlaylist *playlist = new QMediaPlaylist();
	playlist->addMedia(QUrl("res//snd//US-menu.mp3"));
	playlist->setPlaybackMode(QMediaPlaylist::Loop);
	
	
	backgroundMusique = new QMediaPlayer();
	backgroundMusique->setMedia(playlist);
	backgroundMusique->play();
}

void MainWindow::setParametreJeu()
{
	QWidget* savedWidget = this->centralWidget();
	savedWidget->setParent(0);
	this->setCentralWidget(parametreJeu);
	
}
void MainWindow::setParametre()
{
	QWidget* savedWidget = this->centralWidget();
	savedWidget->setParent(0);
	this->setCentralWidget(parametre);
}
void MainWindow::retourMenu()
{
	QWidget* savedWidget = this->centralWidget();
	savedWidget->setParent(0);
	this->setCentralWidget(accueil);
}
void MainWindow::setTableauJeu1()
{
	Player p1 = Player(parametreJeu->txtNom2->text().toStdString(), player1);
	Player p2 = Player(parametreJeu->txtNom1->text().toStdString(), player2);


	parametreJeu->setValues();
	this->diml = parametreJeu->diml;
	this->dimh = parametreJeu->dimh;
	tableauJeu = new TableauJeu(diml,dimh,winl,winh,p1,p2);
	QWidget* savedWidget = this->centralWidget();
	savedWidget->setParent(0);
	QGraphicsView *view = new QGraphicsView(tableauJeu);
	setBackground("res//BackGroundDesert.jpg");
	view->setStyleSheet("background: transparent");
	this->setCentralWidget(view);
	connect(tableauJeu, SIGNAL(winnerSignal(Player, Player)), this, SLOT(setWinner(Player, Player)));
}



/*Active et desactive la musique a partir de parametre*/
void MainWindow::musiqueONandOFF()
{
	if (backgroundMusique->isMuted() == false)
	{
		backgroundMusique->setMuted(true);
	}
	else
	{
		backgroundMusique->setMuted(false);
	}
}

void MainWindow::volumeBackgroundMusic(int volume)
{
	backgroundMusique->setVolume(volume);
}

void MainWindow::setWinner(Player pWin, Player pLost)
{
	QLabel winner;
	QMediaPlaylist *winnerList = new QMediaPlaylist();
	tableauJeu->clear();
	if (pWin.getPlayerType() == player1)
	{
		winner.setText("The mexicans won!");
		winnerList->addMedia(QUrl("res//snd//MX-victory.mp3"));
		backgroundMusique->setPlaylist(winnerList);
		backgroundMusique->play();
		tableauJeu->animationMexicain();
	}
	else if (pWin.getPlayerType() == player2)
	{
		winner.setText("The americans won!");
		winnerList->addMedia(QUrl("res//snd//US-victory.mp3"));
		backgroundMusique->setPlaylist(winnerList);
		backgroundMusique->play();

	}
	
	cout << "Winner" << pWin.getName() << endl;
	cout << "Looser" << pLost.getName() << endl;

	connect(tableauJeu->animation, SIGNAL(&finished()), this, SLOT(backgroundMexicanWin()));

}

void MainWindow::backgroundMexicanWin()
{
	this->setBackground("res//texas_background.jpg");
}



void MainWindow::quitter()
{
	exit(0);
}


