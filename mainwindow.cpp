#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    score_(0)
{

    ui->setupUi(this);
    button_ = new QPushButton("Sam Ao", this);
    button_->setGeometry(QRect(QPoint(100,100), QSize(40, 20)));

    qInfo() << "Connecting the button to function";
    connect(button_, SIGNAL (pressed()), this, SLOT(handlePressMe()));
}

void MainWindow::updateScore() {
    score_++;
    ui->label_2->setText(QString::number(score_));
}

void MainWindow::handlePressMe(){
    updateScore();
    int x = qrand() % 1720;
    int y = qrand() % 1030;
    button_->setGeometry(QRect(QPoint(x,y), QSize(200, 50)));
}

MainWindow::~MainWindow()
{
    delete ui;
    delete button_;
    delete timer_;
    delete timeValue;
}
