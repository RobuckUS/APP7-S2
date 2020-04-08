#include <QWidget>
#include <QCheckBox>
#include <QPushButton>
#include <QVBoxLayout>

class ParametreJeu : public QWidget
{
public:
	ParametreJeu();
	QCheckBox *nbJoueur;
	QCheckBox *dimension;
	QPushButton *jouer;
	QPushButton *retour;
private:
	QVBoxLayout *vlayout;
	void setButton();
	void setCheckbox();
	void setVLayout();
	void setWindow();
};