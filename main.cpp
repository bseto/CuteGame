#include "mainwindow.h"
#include <QApplication>
#include <QPushButton>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.resize(1920,1080);
    //w.setWindowTitle(QString("Hi"));
    w.setWindowTitle
            ((QApplication::translate("childwidget", "Child widget")));
    w.show();

    return a.exec();
}


