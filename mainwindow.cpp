#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    button_ = new QPushButton("Sam Ao", this);
    button_->setGeometry(QRect(QPoint(100,100), QSize(200, 50)));

    qInfo() << "Connecting the button to function";
    connect(button_, SIGNAL (pressed()), this, SLOT(handlePressMe()));
    ui->setupUi(this);
}

void MainWindow::handlePressMe(){
    /*
    qInfo() << "C++ Style Info Message";
    int x = qrand() % 1720;
    int y = qrand() % 1030;
    button_->setGeometry(QRect(QPoint(x,y), QSize(200, 50)));
    */
    button_->setText("Example");
}

MainWindow::~MainWindow()
{
    delete ui;
}
