#ifndef GAMESTATS_H
#define GAMESTATS_H

#include <QObject>
/*
#include <QTimer>
#include <QTime>
*/
#include <QLabel>

//We need this for Signal and Slots
class GameStats : public QObject
{
    //moc will read this
    Q_OBJECT

public:
    GameStats();

public slots:
    void handlePressMe();
    void updateClicks();


private:

    /*
    int correctClicks_;

    // Not to be confused with correctClicks
    // In the future, this score can be calculated by losing points for missed clicks etc
    int gameScore_;
    int totalClicks_;

    QTimer *timer_;
    QTime *timeValue_;
    */


    int score_;
    int clicks_;
};



#endif // GAMESTATS_H
