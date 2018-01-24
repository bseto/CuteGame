#ifndef VIEWSTATS_H
#define VIEWSTATS_H

#include <QPushButton>
#include <QMouseEvent>
#include <QTime>
#include <QTimer>
#include <QString>


class ViewStats : public QObject
{
    Q_OBJECT

public:
    explicit ViewStats(int gameTimeS);
    ~ViewStats();

private slots:
    void handlePressMe();
    void handleEmptyPress(QMouseEvent* event);
    void handleTimerTick();

signals:
    void emitUpdateScore(int score);
    void emitUpdateClicks(int clicks);
    void emitUpdateAccuracy(double accuracy);
    void emitUpdateTimer(QString time);
    void emitTimesUp(int score, int clicks, int gameTimeS);

private:
    void updateScore();
    void updateClicks();

    QTimer *timer_;
    QTime *timeValue_;

    int score_;
    int clicks_;
    int gameTimeS_;
};

#endif // VIEWSTATS_H
