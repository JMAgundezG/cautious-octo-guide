#ifndef ejemplo1_H
#define ejemplo1_H


#include <QtGui>
#include "ui_counterDlg.h"
#include <pthread.h>

class ejemplo1 : public QWidget, public Ui_Counter
{
Q_OBJECT
public:
    ejemplo1();
    virtual ~ejemplo1();
    void start();
    void stop();
	void refresh();

public slots:
	void doButton();

private:
    void runThread(void * pVoid);
    int number;
    pthread_t pthread;
    bool active;
};

#endif // ejemplo1_H
