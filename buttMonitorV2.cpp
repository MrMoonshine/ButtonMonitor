
#include "buttmonitor.h"
#include <wiringPi.h>
#define WAITTIME 100
buttMonitor::buttMonitor(QWidget *parent) :
    QMainWindow(parent)
{
    setupUi(this);
    wiringPiSetupGpio();
    unsigned int x = 0;
    unsigned int state = 0, value = 0;
    int butts[3];
    int *buttpt;
    buttpt = butts;
    *(buttpt+0) = 22;
    *(buttpt+1) = 27;
    *(buttpt+2) = 17;

    for(x = 0;x<sizeof(buttpt);x++){
        pinMode(*(buttpt+x),INPUT);
    }

    for(;;){
        value = 0;
        for(x = 0;x<sizeof(buttpt);x++){
            state = digitalRead(*(buttpt+x));
            value |= ((state & 1)<<x);
        }

        if((value & 1) == 1)
        label_0 -> setStyleSheet("background-color:red");
        else
        label_0 -> setStyleSheet("background-color:black");

        if((value & 2) == 1)
        label_1 -> setStyleSheet("background-color:red");
        else
        label_1 -> setStyleSheet("background-color:black");

        if((value & 4) == 1)
        label_2 -> setStyleSheet("background-color:red");
        else
        label_2 -> setStyleSheet("background-color:black");

        Sleep(WAITTIME);
    }
}