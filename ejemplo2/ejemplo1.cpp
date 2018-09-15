#include "ejemplo1.h"

ejemplo1::ejemplo1(): Ui_Counter()
{

	timer = new timeSignal();
    number = 0;
	setupUi(this);
	show();
	connect(button, SIGNAL(clicked()), this, SLOT(doButton()));
    connect(timer, SIGNAL(signal_sender()), this, SLOT(refresh()));
    timer->start();
}

ejemplo1::~ejemplo1()
{}

void ejemplo1::refresh() {
	number++;
	lcdNumber->display(number);
}

void ejemplo1::doButton()
{
	if(timer->isActive()){
	    timer->stop();
		number = 0;
		lcdNumber->display(number);
	}
	else {
		timer->start();
    }
}




