#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>
class Accueil : public QWidget
{
	Q_OBJECT
public:
	Accueil();
	QPushButton *jouerBtn;
	QPushButton *quitterBtn;
	QPushButton *parametreBtn;
	QPushButton *tableauScoreBtn;

private:
	QVBoxLayout *vlayout;
	void setVLayout();
	void setWindow();
	void setButtons();


};