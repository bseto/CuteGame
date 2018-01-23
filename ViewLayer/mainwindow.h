#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <sstream>
#include <iomanip>
#include <iostream>
#include <QMainWindow>
#include <QLabel>

#include "ViewLayer/viewstats.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void screenUpdateScore(int score);
    void screenUpdateClicks(int clicks);

private:
    Ui::MainWindow *ui;
    QPushButton *button_;

    ViewStats *viewStats_;
};

#endif // MAINWINDOW_H
