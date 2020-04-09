TARGET = ConnectFour
TEMPLATE = vcapp
CONFIG += warn_on qt debug_and_release windows console
DEFINES += QT_DEPRECATED_WARNINGS
HEADERS += src\*.h
SOURCES += src\*.cpp
QT += widgets