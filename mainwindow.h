#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QMouseEvent>
#include <QDebug>
#include <QTimer>
#include <QTime>

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

private:
    void updateScore();
    void updateClicks();

    Ui::MainWindow *ui;
    QPushButton *button_;
    int score_;
    int clicks_;

    QTimer *timer_;
    QTime *timeValue_;
};

#endif // MAINWINDOW_H
