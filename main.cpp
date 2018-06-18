#include "mainwindow.h"
#include "ventanasingleton.h"
#include <QApplication>

VentanaSingleton *VentanaSingleton::s_instance = 0;

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
