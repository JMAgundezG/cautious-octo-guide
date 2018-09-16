//
// Created by jmagundezg on 12/09/18.
//

#include "signalSender.h"

void * signal_sender(void *cl){
    ejemplo1 *clase = (ejemplo1 *) cl;
    int number = 0;
    double inicio = (double)clock();
    double final;
    clase->lcdNumber->display(number);
    for(;;){
        final = (double)clock();
        if(((final - inicio) / CLOCKS_PER_SEC) >= 1.0){
            inicio = final;
            number++;
            clase->lcdNumber->display(number);
            std::cout << inicio << std::endl;
        }
    }
}