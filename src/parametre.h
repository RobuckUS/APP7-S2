#include<QWidget>
#include<QPushButton>
#include<QSlider>
#include<QVBoxLayout>
#include<QCheckBox>

class Parametre : public QWidget
{
	Q_OBJECT
public:
	Parametre();
	QPushButton *musiqueBtn;
	QPushButton *pleinEcranBtn;
	QPushButton *retourBtn;
	QSlider *volumeMusiqueSlider;
	QCheckBox *themeCheckBox;
public slots:
	void setMusiqueBtn();
	void setPleinEcranBtn();
	void musiqueBtnAdjust(int volume);
private:
	QVBoxLayout *vlayout;
	void setButtons();
	void setVLayout();
	void setWindow();
	bool musique;
	
};