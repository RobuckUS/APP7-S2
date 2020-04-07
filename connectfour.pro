TARGET = ConnectFour
TEMPLATE = vcapp

CONFIG += warn_on qt debug_and_release windows console


DEFINES += QT_DEPRECATED_WARNINGS

HEADERS += \
        src\accueil.h \
        src\mainWindow.h \
        src\parametre.h \
        src\parametreJeu.h \

SOURCES += \
        src\main.cpp \
        src\accueil.cpp \
        src\mainWindow.cpp \
        src\parametre.cpp \
        src\parametreJeu.cpp \

QT += widgets
