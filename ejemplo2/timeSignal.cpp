//
// Created by jmagundezg on 12/09/18.
//

#include "timeSignal.h"

timeSignal::timeSignal() : QThread{
        period = 1000;
}

timeSignal::timeSignal(int _period) {
    period = _period;
}

void timeSignal::start() {
        active = true;
        double inicio = (double) clock();
        double final;
        while (active) {
            final = (double) clock();
            if (((final - inicio) / CLOCKS_PER_SEC) * period >= 1) {
                inicio = final;
                emit timeout();
            }
        }
    }
}

void setPeriod(int _period) {
    period = _period;
}

timeSignal::~timeSignal() {}


void timeSignal::stop() {
    active = false;
}

bool timeSignal::isActive() {
    return active;
}