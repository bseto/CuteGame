#ifndef VIEWSTATS_H
#define VIEWSTATS_H

#include <QPushButton>


class ViewStats : public QObject
{
    Q_OBJECT

public:
    explicit ViewStats();
    ~ViewStats();

protected:
    //void mousePressEvent(QMouseEvent *event) override;

private slots:
    void handlePressMe();

signals:
    void emitUpdateScore(int score);
    void emitUpdateClicks(int clicks);
    void emitUpdateAccuracy(int accuracy);

private:
    void updateScore();
    void updateClicks();
    void updateAccuracy();


    /*
    QTimer *timer_;
    QTime *timeValue_;
    */

    int score_;
    int clicks_;
};

#endif // VIEWSTATS_H
