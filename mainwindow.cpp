#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    score_(0),
    clicks_(0)
{

    ui->setupUi(this);
    button_ = new QPushButton("Sam Ao", this);
    button_->setGeometry(QRect(QPoint(100,100), QSize(40, 20)));

    qInfo() << "Connecting the button to function";
    connect(button_, SIGNAL (pressed()), this, SLOT(handlePressMe()));
}

void MainWindow::updateScore() {
    score_++;
    ui->ScoreCount->setText(QString::number(score_));
}

void MainWindow::updateClicks() {
    clicks_++;
    updateAccuracy();
    ui->ClicksCount->setText(QString::number(clicks_));
}

void MainWindow::updateAccuracy() {
    double accuracy = (double) score_ / (double) clicks_ * 100;
    ui->AccuracyCount->setText(QString::number(accuracy, 'g', 5) + "%");
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        updateClicks();
    }
}

void MainWindow::handlePressMe(){
    updateScore();
    updateClicks();
    int x = qrand() % 1720;
    int y = qrand() % 1030;
    button_->setGeometry(QRect(QPoint(x,y), QSize(200, 50)));
}

MainWindow::~MainWindow()
{
    delete ui;
    delete button_;
    delete timer_;
    delete timeValue_;
}
