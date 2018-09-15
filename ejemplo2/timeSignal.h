//
// Created by jmagundezg on 12/09/18.
//

#include <pthread.h>
#include <stdlib.h>

#include "signalSender.h"
#ifndef EJEMPLO1_TIMESIGNAL_H
#define EJEMPLO1_TIMESIGNAL_H


class timeSignal {

private:
    pthread_t pthread;
    bool active;

public:
    timeSignal();
    ~timeSignal();
    void start();
    void stop();
    bool isActive();

};


#endif //EJEMPLO1_TIMESIGNAL_H
