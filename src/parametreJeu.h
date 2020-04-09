#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QSPINBOX>
#include <QSTRING>
#include <QMESSAGEBOX>


class ParametreJeu : public QWidget
{
public:
	ParametreJeu();
	QMessageBox * messagebox;
	QPushButton *unJoueur;
	QPushButton *deuxJoueurs;
	QSpinBox *largeur;
	QSpinBox *hauteur;
	QPushButton *jeuretourbtn;
	QLabel *labelL;
	QLabel *labelH;
	int nbj;
	int diml;
	int dimh;
	void setValues();
private:
	QHBoxLayout *hlayout;
	QHBoxLayout *hlayoutdim;
	QVBoxLayout *vlayout;
	QHBoxLayout *hlayoutval;
	void setButton();
	void setHlayout();
	void setVLayout();
	void setWindow();	
	const int MaxSize = 20;
	
};