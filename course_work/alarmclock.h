#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <chrono>
#include <thread>
#include "event.h"
#ifndef ALARMCLOCK_H
#define ALARMCLOCK_H


class AlarmClock {
public:
    AlarmClock(const std::string& eventFile, int numEvents) : events(loadEvents(eventFile)), numEvents(numEvents) {}
    void start();

private:
    std::vector<Event> events;
    int numEvents;

    std::vector<Event> loadEvents(const std::string& eventFile);
    std::vector<Event> generateEventSequence();
};

#endif // ALARMCLOCK_H
