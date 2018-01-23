#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <sstream>
#include <iomanip>
#include <iostream>
#include <QMouseEvent>
#include <QMainWindow>
#include <QLabel>

#include <QDebug>
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

protected:
    void mousePressEvent(QMouseEvent *event) override;

private slots:
    void screenUpdateScore(int score);
    void screenUpdateClicks(int clicks);
    void screenUpdateAccuracy(double accuracy);
    void screenUpdateTimer(QString time);

    void updateTimesUp(int score, int clicks, int gameTimeS);

signals:
    void emitMousePressEvent(QMouseEvent *event);

private:
    Ui::MainWindow *ui;
    QPushButton *button_;

    ViewStats *viewStats_;
};

#endif // MAINWINDOW_H
