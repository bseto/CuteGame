
#include "ViewLayer/viewstats.h"

ViewStats::ViewStats():
    timer_(new QTimer()),
    timeValue_(new QTime(0, 0, 30)),
    score_(0),
    clicks_(0)
{
    connect(timer_, SIGNAL(timeout()),
            this, SLOT(handleTimerTick()));
    // The timer_ will `timeout` every 1000ms
    timer_->start(1000);
}

ViewStats::~ViewStats(){
}

//PRIVATE SLOTS
void ViewStats::handlePressMe() {
    updateScore();
    updateClicks();
}

void ViewStats::handleEmptyPress(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        // Update clicks will increment clicks and
        // emit to update clicks and accuracy w/o incrementing score
        updateClicks();
    }
}

void ViewStats::handleTimerTick() {
    timeValue_->setHMS(0,
        timeValue_->addSecs(-1).minute(),
        timeValue_->addSecs(-1).second());
    emitUpdateTimer(timeValue_->toString());
}

//PRIVATE
void ViewStats::updateScore() {
    score_++;
    emitUpdateScore(score_);
}
void ViewStats::updateClicks() {
    clicks_++;
    emitUpdateClicks(clicks_);
    emitUpdateAccuracy((double) score_ / (double) clicks_ * 100);
}


