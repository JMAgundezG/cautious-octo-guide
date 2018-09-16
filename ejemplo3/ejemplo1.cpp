#include "ejemplo1.h"

ejemplo1::ejemplo1() : Ui_Counter() {

    number = 0;
    setupUi(this);
    active = false;
    show();
    connect(button, SIGNAL(clicked()), this, SLOT(doButton()));
}

ejemplo1::~ejemplo1() {}


void ejemplo1::doButton() {
    if (active) {
        stop();
    } else {
        start();
    }
}

void ejemplo1::start() {
    if (!active) {
        active = true;
        void * ptr = (void*) this;
        pthread_create(&pthread, NULL, signal_sender, ptr); // Creamos el thread
    }
}


void ejemplo1::stop() {
    if(active){
        pthread_cancel(pthread);
        pthread_join(pthread, NULL);
        active = false;
        number = 0;
        lcdNumber->display(number);
    }
}


