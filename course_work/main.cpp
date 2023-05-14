#include <QApplication>
#include "mainwindow.h"
#include "evcode.h"
#include "alarmclock.h"
#include <iostream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    std::cout << "1234567890";
    srand(static_cast<unsigned int>(time(nullptr)));
    AlarmClock alarmClock("events.txt", 20);
    alarmClock.start();
    return a.exec();
}
