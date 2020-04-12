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
	connect(parametreJeu->unJoueur, SIGNAL(clicked()), this, SLOT(setTableauJeu1()));
	connect(parametreJeu->deuxJoueurs, SIGNAL(clicked()), this, SLOT(setTableauJeu2()));
	

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
	parametreJeu->setValues();
	this->diml = parametreJeu->diml;
	this->dimh = parametreJeu->dimh;
	tableauJeu = new TableauJeu(diml,dimh,winl,winh);
	QWidget* savedWidget = this->centralWidget();
	savedWidget->setParent(0);
	QGraphicsView *view = new QGraphicsView(tableauJeu);
	setBackground("res//BackGroundDesert.jpg");
	view->setStyleSheet("background: transparent");
	this->setCentralWidget(view);
}

void MainWindow::setTableauJeu2()
{
	parametreJeu->setValues();
	this->diml = parametreJeu->diml;
	this->dimh = parametreJeu->dimh;
	tableauJeu = new TableauJeu();
	QWidget* savedWidget = this->centralWidget();
	savedWidget->setParent(0);
	QGraphicsView *view = new QGraphicsView(tableauJeu);
	setBackground("res//BackGroundDesert.jpg");
	view->setStyleSheet("background: transparent");
	this->setCentralWidget(view);
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

void MainWindow::quitter()
{
	exit(0);
}


