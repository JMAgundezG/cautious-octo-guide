//
// Created by jmagundezg on 12/09/18.
//

#include "timeSignal.h"

timeSignal::timeSignal() {
    pthread_setcanceltype(PTHREAD_CANCEL_ASYNCHRONOUS, NULL);
}

timeSignal::~timeSignal() {}

void timeSignal::start() {
    if (!active){
        pthread_create(&pthread, NULL, signal_sender, NULL); // Creamos el thread
        active = true;
    }
}

void timeSignal::stop() {
    if (active){
        pthread_cancel(pthread);
    }
}

bool timeSignal::isActive() {
    return active;
}