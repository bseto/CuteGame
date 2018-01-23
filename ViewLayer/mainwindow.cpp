#include "ViewLayer/mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    score_(0),
    clicks_(0)
{
    ui->setupUi(this);

    button_ = new QPushButton("Click Me", this);
    button_->setGeometry(QRect(QPoint(100,100), QSize(200, 50)));
    connect(button_, SIGNAL (pressed()), this, SLOT(handlePressMe()));

    timer_ = new QTimer();
    timeValue_ = new QTime(0, 0, 30);
    connect(timer_, SIGNAL(timeout()), this, SLOT(setDisplay()));
    timer_->start(1000);
}

void MainWindow::setDisplay() {
    this->timeValue_->setHMS(0, this->timeValue_->addSecs(-1).minute(),
                             this->timeValue_->addSecs(-1).second());
    ui->TimeCount->setText(timeValue_->toString());
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
