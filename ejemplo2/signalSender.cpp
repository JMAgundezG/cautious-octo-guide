//
// Created by jmagundezg on 12/09/18.
//

#include "signalSender.h"

void * signal_sender(void * pVoid){
    double inicio = (double)clock();
    double final;
    for(;;){
        final = (double)clock();
        if(((final - inicio) / CLOCKS_PER_SEC) >= 1.0){
            inicio = clock();
            raise(SIGUSR1);
            std::cout << inicio << std::endl;
        }
    }
}