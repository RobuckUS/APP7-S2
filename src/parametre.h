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
	QPushButton *retourBtn;
	QSlider *volumeMusiqueSlider;
public slots:
	void setMusiqueBtn();
	void musiqueBtnAdjust(int volume);
private:
	QVBoxLayout *vlayout;
	void setButtons();
	void setVLayout();
	void setWindow();
	bool musique;
	
};