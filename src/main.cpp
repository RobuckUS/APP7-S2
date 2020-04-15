#include <QFontDataBase>
#include <QApplication>
#include "mainWindow.h"


int main(int argc, char ** argv)
{
	
	QApplication app(argc, argv);
	QFontDatabase database;
	database.addApplicationFont("lib//fonts//ShowcardGothic.ttf");
	MainWindow gui;
	
	gui.show();
	return app.exec();

}