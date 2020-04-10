#include <QMainWindow>
#include <qapplication.h>
#include <qdesktopwidget.h>
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
private:
	void setActions();
	void setBackground(QString fileName);
	Accueil *accueil;
	Parametre *parametre;
	ParametreJeu *parametreJeu;
	TableauJeu *tableauJeu;
};