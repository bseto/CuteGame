#ifndef VIEWSTATS_H
#define VIEWSTATS_H

#include <QPushButton>
#include <QMouseEvent>


class ViewStats : public QObject
{
    Q_OBJECT

public:
    explicit ViewStats();
    ~ViewStats();

private slots:
    void handlePressMe();
    void handleEmptyPress(QMouseEvent* event);

signals:
    void emitUpdateScore(int score);
    void emitUpdateClicks(int clicks);
    void emitUpdateAccuracy(double accuracy);

private:
    void updateScore();
    void updateClicks();


    /*
    QTimer *timer_;
    QTime *timeValue_;
    */

    int score_;
    int clicks_;
};

#endif // VIEWSTATS_H
