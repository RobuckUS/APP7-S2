#include <QMainWindow>
#include <QMediaPlaylist>
#include <qapplication.h>
#include <qdesktopwidget.h>
#include <QMediaPlayer>
#include "accueil.h"
#include "parametre.h"
#include "parametreJeu.h"
#include "tableauJeu.h"
#include "tableauScore.h"
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
signals:
	void winnerSignal (Player pWin, Player pLost);
public slots:
	void setParametre();
	void setParametreJeu();
	void retourMenu();
	void setTableauJeu1();
	void quitter();
	void musiqueONandOFF();
	void volumeBackgroundMusic(int volume);
	void setWinner(Player pWin, Player pLost);
	void backgroundMexicanWin();
	void backgroundTrumpWin();
	void gestionFinPartie();
	void retourAccueil();
	void rejouer();

	//add
	void setTableauScore();

private:
	void setActions();
	void setBackground(QString fileName);
	void setBackgroundMusique();
	
	Accueil *accueil;
	Parametre *parametre;

	//add
	TableauScore* tableauScore;

	ParametreJeu *parametreJeu;
	TableauJeu *tableauJeu;
	QMediaPlayer *backgroundMusique;


};