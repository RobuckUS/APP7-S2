#include <QMainWindow>
#include "accueil.h"
#include "parametre.h"
#include "parametreJeu.h"

class MainWindow : public QMainWindow
{
	Q_OBJECT
public:
	MainWindow();
public slots:
	void setParametre();
	void setParametreJeu();
	void retourMenu();
private:
	void setActions();
	Accueil *accueil;
	Parametre *parametre;
	ParametreJeu *parametreJeu;
};