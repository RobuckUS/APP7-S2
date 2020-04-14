#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QScrollArea>
#include <QListWidget>
#include <QStringList>

class TableauScore : public QWidget
{
	Q_OBJECT
public:
	TableauScore();
	void showScore();
	void setButtons();
	void setVLayout();
	void setWindow();
	QPushButton* retourBtn;

private:
	QVBoxLayout* vlayout;
	QHBoxLayout* hlayoutList;

	//QStringList listFileLine;
	QStringList splitFileLine;
	QStringList listFileLine;

	QLabel* showFileText;

	QScrollArea* zoneScroll;
	QListWidget* viewList;

};
