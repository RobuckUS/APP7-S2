#include <QMainWindow>
#include <QMediaPlaylist>
#include <qapplication.h>
#include <qdesktopwidget.h>
#include <QMediaPlayer>
#include "accueil.h"
#include "parametre.h"
#include "parametreJeu.h"
#include "tableauJeu.h"
#include <QSTYLE>

class MainWindow : public QMainWindow
{
	Q_OBJECT
public:
	MainWindow();
	~MainWindow();
	int diml;
	int dimh;
	int winl;
	int winh;
public slots:
	void setParametre();
	void setParametreJeu();
	void retourMenu();
	void setTableauJeu1();
	void setTableauJeu2();
	void quitter();
	void musiqueONandOFF();
	void volumeBackgroundMusic(int volume);

private:
	void setActions();
	void setBackground(QString fileName);
	void setBackgroundMusique();

	Accueil *accueil;
	Parametre *parametre;
	ParametreJeu *parametreJeu;
	TableauJeu *tableauJeu;
	QMediaPlayer *backgroundMusique;

};