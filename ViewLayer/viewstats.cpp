
#include "ViewLayer/viewstats.h"

ViewStats::ViewStats():
    score_(0),
    clicks_(0)
{}

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


