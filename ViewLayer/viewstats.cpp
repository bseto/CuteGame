
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

//PRIVATE
void ViewStats::updateScore() {
    score_++;
    emitUpdateScore(score_);
}
void ViewStats::updateClicks() {
    clicks_++;
    emitUpdateClicks(clicks_);
}
