TEMPLATE     = vcapp
TARGET       = ConnectFour
CONFIG      += warn_on qt debug_and_release windows console
HEADERS     += accueil.h mainWindow.h parametre.h
SOURCES     += accueil.cpp parametre.cpp MainWindow.cpp main.cpp
INCLUDEPATH += ../APP7-S2 ../APP7-S2/Ressources
QT += widgets
