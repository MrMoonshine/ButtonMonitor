n#include "buttmonitor.h"
#include <wiringPi.h>
#include <QTimer>
#define WAITTIME 100

void buttMonitor::buttISR(){
    value = 0;
   for(unsigned int x = 0;x<sizeof(buttpt);x++){
    state = digitalRead(*(buttpt+x));
    value |= ((state & 1)<<x);
   }

        if((value & 1) > 0)
        label_0 -> setStyleSheet("background-color:black");
        else
        label_0 -> setStyleSheet("background-color:red");

        if((value & 2) > 0)
        label_1 -> setStyleSheet("background-color:black");
        else
        label_1 -> setStyleSheet("background-color:red");

        if((value & 4) > 0)
        label_2 -> setStyleSheet("background-color:black");
        else
        label_2 -> setStyleSheet("background-color:red");
}

buttMonitor::buttMonitor(QWidget *parent) :
    QMainWindow(parent)
{
    setupUi(this);
    wiringPiSetupGpio();

    buttpt = butts;
    *(buttpt+0) = 22;
    *(buttpt+1) = 27;
    *(buttpt+2) = 17;

    for(unsigned int x = 0;x<sizeof(buttpt);x++){
        pinMode(*(buttpt+x),INPUT);
    }

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()),SLOT(buttISR()));
    timer->start(WAITTIME);


}
