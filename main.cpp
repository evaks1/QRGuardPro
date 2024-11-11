// main.cpp
#include <QApplication>
#include "MainWindow.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    // Set Application Information
    QApplication::setApplicationName("QRGuardPro");
    QApplication::setApplicationVersion("1.0");

    // Create and Show Main Window
    MainWindow mainWindow;
    mainWindow.show();

    return app.exec();
}