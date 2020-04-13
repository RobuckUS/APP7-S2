#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QSPINBOX>
#include <QSTRING>
#include <QMESSAGEBOX>
#include <QLineEdit>

class ParametreJeu : public QWidget
{
	Q_OBJECT
public:
	ParametreJeu();
	QMessageBox * messagebox;
	QPushButton *deuxJoueurs;
	QSpinBox *largeur;
	QSpinBox *hauteur;
	QPushButton *jeuretourbtn;

	QLabel *lblNameP1;
	QLabel *lblNameP2;


	QLabel *labelL;
	QLabel *labelH;

	QLineEdit *txtNom1;
	QLineEdit *txtNom2;

	int nbj;
	int diml;
	int dimh;
	void setValues();
private:
	QHBoxLayout *hlayout;
	QHBoxLayout *hname;
	QHBoxLayout *hlayoutval;
	
	QVBoxLayout *vlayout;

	void setButton();
	void setHlayout();
	void setVLayout();
	void setWindow();	
	const int MaxSize = 20;
	
};