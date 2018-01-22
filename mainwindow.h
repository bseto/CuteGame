#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QDebug>
#include <QTimer>
#include <QTime>
#include <QWidget>

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
    void handlePressMe();

private:
    void updateScore();

    Ui::MainWindow *ui;
    QPushButton *button_;
    QWidget timeWidget_;

    int score_;
    int clicks_;

    QTimer *timer_;
    QTime *timeValue_;

};

#endif // MAINWINDOW_H
