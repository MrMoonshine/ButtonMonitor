#ifndef BUTTMONITOR_H
#define BUTTMONITOR_H

#include "ui_buttmonitor.h"

class buttMonitor : public QMainWindow, private Ui::buttMonitor
{
    Q_OBJECT

public:
    explicit buttMonitor(QWidget *parent = 0);
    QTimer *timer;
    void isr();
    int *buttpt;
    int value, state;
    int butts[3];
private slots:
    void buttISR();
};

#endif // BUTTMONITOR_H
