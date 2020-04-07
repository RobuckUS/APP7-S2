#include<QWidget>
#include<QPushButton>
#include<QSlider>
#include<QVBoxLayout>
#include<QCheckBox>

class Parametre : public QWidget
{
public:
	Parametre();
	QPushButton *musiqueBtn;
	QPushButton *pleinEcranBtn;
	QPushButton *retourBtn;
	QSlider *volumeMusiqueSlider;
	QSlider *volumeEffetSlider;
	QCheckBox *themeCheckBox;
public slots:
	void setMusiqueBtn();
	void setPleinEcranBtn();
private:
	QVBoxLayout *vlayout;
	void setButtons();
	void setVLayout();
	void setWindow();
	
};