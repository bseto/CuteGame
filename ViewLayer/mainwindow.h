#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <sstream>
#include <iomanip>
#include <iostream>
#include <QMainWindow>
#include <QPushButton>
#include <QMouseEvent>
#include <QDebug>
#include <QLabel>
#include <QTime>
#include <QTimer>

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
    void handlePressMe();
    void setDisplay();

private:
    void updateScore();
    void updateClicks();
    void updateAccuracy();

    Ui::MainWindow *ui;
    QPushButton *button_;

    int score_;
    int clicks_;

    QTimer *timer_;
    QTime *timeValue_;


};

#endif // MAINWINDOW_H
