#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QSPINBOX>
#include <QSTRING>
#include <QMESSAGEBOX>


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
	QLabel *labelL;
	QLabel *labelH;
	int nbj;
	int diml;
	int dimh;
	void setValues();
private:
	QHBoxLayout *hlayout;
	QVBoxLayout *vlayout;
	QHBoxLayout *hlayoutval;
	


	void setButton();
	void setHlayout();
	void setVLayout();
	void setWindow();	
	const int MaxSize = 20;
	
};