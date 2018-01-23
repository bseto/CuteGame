#include "ViewLayer/mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    viewStats_(new ViewStats)
{
    ui->setupUi(this);

    button_ = new QPushButton("Click Me", this);
    button_->setGeometry(QRect(QPoint(100,100), QSize(200, 50)));

    connect(button_, SIGNAL(pressed()),
            &(*viewStats_), SLOT(handlePressMe())); //seems kinda hackery

    connect(&(*viewStats_), SIGNAL(emitUpdateScore(int)),
            this, SLOT(screenUpdateScore(int)));
    connect(&(*viewStats_), SIGNAL(emitUpdateClicks(int)),
            this, SLOT(screenUpdateClicks(int)));
}


//SLOTS
void MainWindow::screenUpdateScore(int value) {
    int x = qrand() % 1720;
    int y = qrand() % 1030;
    button_->setGeometry(QRect(QPoint(x,y), QSize(200, 50)));

    ui->ScoreCount->setText(QString::number(value));
}
void MainWindow::screenUpdateClicks(int clicks) {
    ui->ClicksCount->setText(QString::number(clicks));
}

MainWindow::~MainWindow()
{
    delete ui;
    delete button_;
    //delete timer_;
    //delete timeValue_;
}
