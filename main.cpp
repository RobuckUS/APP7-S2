#include <QApplication>
#include "mainWindow.h"


int main(int argc, char ** argv)
{
	QApplication app(argc, argv);
	MainWindow gui;
	gui.show();
	return app.exec();

}